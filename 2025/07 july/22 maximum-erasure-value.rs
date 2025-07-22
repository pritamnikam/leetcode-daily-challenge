// 1695. maximum-erasure-value
// https://leetcode.com/problems/maximum-erasure-value

use std::collections::HashSet;

impl Solution {
    pub fn maximum_unique_subarray(nums: Vec<i32>) -> i32 {
        let mut seen = HashSet::new();
        let (mut left, mut max_sum, mut current_sum) = (0, 0, 0);

        for right in 0..nums.len() {
            while seen.contains(&nums[right]) {
                seen.remove(&nums[left]);
                current_sum -= nums[left];
                left += 1;
            }

            seen.insert(nums[right]);
            current_sum += nums[right];
            max_sum = max_sum.max(current_sum);
        }

        max_sum
    }
}
