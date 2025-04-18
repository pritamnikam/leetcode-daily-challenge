// maximum-ascending-subarray-sum
// https://leetcode.com/problems/maximum-ascending-subarray-sum/

impl Solution {
    pub fn max_ascending_sum(nums: Vec<i32>) -> i32 {
        nums
            .chunk_by(|a, b| b > a)
            .map(|c| c.iter().sum())
            .max()
            .unwrap()
    }
}
