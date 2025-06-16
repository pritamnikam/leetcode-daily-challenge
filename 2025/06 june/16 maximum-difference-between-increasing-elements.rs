// 2016 maximum-difference-between-increasing-elements
// https://leetcode.com/problems/maximum-difference-between-increasing-elements

impl Solution {
    pub fn maximum_difference(nums: Vec<i32>) -> i32 {
        let n = nums.len();
        let (mut ans, mut premin) = (-1, nums[0]);

        for i in 1..n {
            if nums[i] > premin {
                ans = ans.max(nums[i] - premin);
            } else {
                premin = nums[i];
            }
        }

        ans
    }
}
