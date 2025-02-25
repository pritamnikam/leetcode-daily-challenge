// number-of-sub-arrays-with-odd-sum
// https://leetcode.com/problems/number-of-sub-arrays-with-odd-sum/

const MOD: usize = 1_000_000_007;

impl Solution {
    pub fn num_of_subarrays(arr: Vec<i32>) -> i32 {
        let mut memo = (0, 0);
        let mut t = 0;

        for &v in &arr {
            t += v % 2;
            if t % 2 == 0 {
                memo.0 += 1;
            } else {
                memo.1 += 1;
            }
        }

        let mut result = 0;
        for v in arr {
            result += memo.1;
            result %= MOD;

            if v % 2 == 0 {
                memo.0 -= 1;
            } else {
                memo.1 -= 1;
                std::mem::swap(&mut memo.0, &mut memo.1);
            }
        }

        result as i32
    }
}
