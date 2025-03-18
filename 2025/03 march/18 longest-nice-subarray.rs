// 2401. longest-nice-subarray
// https://leetcode.com/problems/longest-nice-subarray

impl Solution {
    pub fn longest_nice_subarray(nums: Vec<i32>) -> i32 {
        let (mut left, mut right, mut mask, n, mut ans) = (0,0,0, nums.len(), 1);

        while right < n {
            if mask & nums[right] == 0 {
                ans = ans.max(right - left + 1);
            } else {
                while left < right && (mask & nums[right] != 0) {
                    mask = mask ^ nums[left];
                    left += 1;
                }
            }
            mask = mask ^ nums[right];
            right += 1;
        }
        ans as i32
    }
}
