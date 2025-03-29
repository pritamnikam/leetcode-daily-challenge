// 2818. apply-operations-to-maximize-score
// https://leetcode.com/problems/apply-operations-to-maximize-score

use std::collections::HashSet;

const MOD: i64 = 1_000_000_007;

impl Solution {
    // Compute (a^n) % p using modular exponentiation
    fn mod_pow(a: i64, mut n: i64, p: i64) -> i64 {
        let mut result = 1;
        let mut base = a % p;
        while n > 0 {
            if n & 1 == 1 {
                result = (result * base) % p;
            }
            base = (base * base) % p;
            n >>= 1;
        }
        result
    }

    // Count the number of unique prime factors for a given number
    fn count_prime_factors(mut num: i32) -> usize {
        let mut primes = HashSet::new();
        let mut factor = 2;
        while factor * factor <= num {
            while num % factor == 0 {
                primes.insert(factor);
                num /= factor;
            }
            factor += 1;
        }
        if num > 1 {
            primes.insert(num);
        }
        primes.len()
    }

    // Find the nearest greater element to the left for each index
    fn next_greater_on_left(prime_factors: &[usize]) -> Vec<i32> {
        let mut stack = Vec::new();
        let mut result = vec![-1; prime_factors.len()];
        for (i, &value) in prime_factors.iter().enumerate() {
            while let Some(&last) = stack.last() {
                if prime_factors[last] >= value {
                    break;
                }
                stack.pop();
            }
            if let Some(&last) = stack.last() {
                result[i] = last as i32;
            }
            stack.push(i);
        }
        result
    }

    // Find the nearest greater element to the right for each index
    fn next_greater_on_right(prime_factors: &[usize]) -> Vec<i32> {
        let mut stack = Vec::new();
        let mut result = vec![prime_factors.len() as i32; prime_factors.len()];
        for i in (0..prime_factors.len()).rev() {
            while let Some(&last) = stack.last() {
                if prime_factors[last] > prime_factors[i] {
                    break;
                }
                stack.pop();
            }
            if let Some(&last) = stack.last() {
                result[i] = last as i32;
            }
            stack.push(i);
        }
        result
    }

    pub fn maximum_score(nums: Vec<i32>, k: i32) -> i32 {
        let n = nums.len();
        let mut prime_factors = vec![0; n];

        // Calculate prime factor counts for all elements
        for i in 0..n {
            prime_factors[i] = Solution::count_prime_factors(nums[i]);
        }

        // Determine the boundaries for each index
        let left_boundaries = Solution::next_greater_on_left(&prime_factors);
        let right_boundaries = Solution::next_greater_on_right(&prime_factors);

        // Calculate contribution count for each number
        let mut contributions = Vec::new();
        for i in 0..n {
            let left = left_boundaries[i] as usize;
            let right = right_boundaries[i] as usize;
            let count = ((i - left) * (right - i)) as i64;
            contributions.push((nums[i] as i64, count));
        }

        // Sort by values in descending order
        contributions.sort_by(|a, b| b.0.cmp(&a.0));

        // Calculate the maximum score
        let mut result = 1;
        let mut remaining_k = k as i64;
        for (value, count) in contributions {
            if remaining_k <= 0 {
                break;
            }
            let moves = remaining_k.min(count);
            result = (result * Solution::mod_pow(value, moves, MOD)) % MOD;
            remaining_k -= moves;
        }

        result as i32
    }
}
