// 1752. check-if-array-is-sorted-and-rotated
// https://leetcode.com/problems/check-if-array-is-sorted-and-rotated/

impl Solution {
    pub fn check(nums: Vec<i32>) -> bool {
        let n = nums.len();
        let Some(k) = (1..n).find(|&i| nums[i-1] > nums[i]) else {return true};
        nums[n-1] <= nums[0] && (k+1..n).all(|i| nums[i-1] <= nums[i])
    }
}
