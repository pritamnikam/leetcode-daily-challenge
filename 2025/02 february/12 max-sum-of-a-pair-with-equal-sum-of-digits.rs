// 2342. max-sum-of-a-pair-with-equal-sum-of-digits
// https://leetcode.com/problems/max-sum-of-a-pair-with-equal-sum-of-digits/

use std::collections::{HashMap};

impl Solution {

    fn sum_of_digits(mut num: i32) -> i32 {
        let mut sum = 0;
        while num > 0 {
            sum += num % 10;
            num /= 10;
        }
        sum
    }

    pub fn max_sum(nums: Vec<i32>) -> i32 {
        let mut max_sum = -1;
        let mut digit_sum_map: HashMap<i32, i32> = HashMap::new();

        for &num in &nums {
            let digit_sum = Self::sum_of_digits(num);
            
            if let Some(&prev_max) = digit_sum_map.get(&digit_sum) {
                max_sum = max_sum.max(prev_max + num);
            }
            
            digit_sum_map.insert(digit_sum, digit_sum_map.get(&digit_sum).copied().unwrap_or(0).max(num));
        }

        max_sum
    }
        
}
