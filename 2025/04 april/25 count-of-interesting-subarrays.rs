// 2845. count-of-interesting-subarrays
// https://leetcode.com/problems/count-of-interesting-subarrays

use std::collections::HashMap;

impl Solution {
    pub fn count_interesting_subarrays(nums: Vec<i32>, modulo: i32, k: i32) -> i64 {
        let n = nums.len();
        let mut cnt: HashMap<i32, i32> = HashMap::new();
        let mut res: i64 = 0;
        let mut prefix: i32 = 0;
        *cnt.entry(0).or_insert(0) += 1;
        for i in 0..n {
            if nums[i] % modulo == k {
                prefix += 1;
            }
            res += *cnt.get(&((prefix - k + modulo) % modulo)).unwrap_or(&0) as i64;
            *cnt.entry(prefix % modulo).or_insert(0) += 1;
        }
        res
    }
}
