// 3487. maximum-unique-subarray-sum-after-deletion
// https://leetcode.com/problems/maximum-unique-subarray-sum-after-deletion

use std::collections::HashSet;
impl Solution {
    pub fn max_sum(nums: Vec<i32>) -> i32 {
        let positive_nums_set: HashSet<i32> = nums.iter().filter(|&&x| x > 0).cloned().collect();

        if positive_nums_set.is_empty() {
            *nums.iter().max().unwrap()
        } else {
            positive_nums_set.iter().sum()
        }
    }
}
