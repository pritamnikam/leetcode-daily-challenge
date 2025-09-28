// largest-perimeter-triangle
// https://leetcode.com/problems/largest-perimeter-triangle

impl Solution {
    pub fn largest_perimeter(nums: Vec<i32>) -> i32 {
        let mut nums = nums;
        let n = nums.len();
        nums.sort_unstable();

        for i in (0..n-2).rev() {
            if (nums[i] + nums[i + 1] > nums[i + 2]) {
                return nums[i] + nums[i + 1] + nums[i + 2];
            }
        }
        0 as i32
    }
}
