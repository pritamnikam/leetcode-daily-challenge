// 3396. minimum-number-of-operations-to-make-elements-in-array-distinct
// https://leetcode.com/problems/minimum-number-of-operations-to-make-elements-in-array-distinct

use std::collections::HashSet;

impl Solution {
    pub fn minimum_operations(nums: Vec<i32>) -> i32 {
        (0..nums.len()).rev()
            .scan(HashSet::new(), |set, i| set.insert(nums[i]).then_some(i))
            .last()
            .map_or(0, |i| ((i + 2)/3) as i32)
    }
}
