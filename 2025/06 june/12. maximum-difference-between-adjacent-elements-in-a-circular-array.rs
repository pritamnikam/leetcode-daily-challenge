// 3423. maximum-difference-between-adjacent-elements-in-a-circular-array
// https://leetcode.com/problems/maximum-difference-between-adjacent-elements-in-a-circular-array

impl Solution {
    pub fn max_adjacent_distance(nums: Vec<i32>) -> i32 {
        let n = nums.len();
        let mut res = (nums[0] - nums[n - 1]).abs();
        for i in 0..n-1 {
            res = res.max((nums[i] - nums[i+1]).abs());
        }

        res
    }
}
