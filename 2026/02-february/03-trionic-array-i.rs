// trionic-array-i
// https://leetcode.com/problems/trionic-array-i

impl Solution {
    pub fn is_trionic(nums: Vec<i32>) -> bool {
        let n = nums.len();
        let mut i = 1;

        while i < n && nums[i - 1] < nums[i] {
            i += 1;
        }

        let p = i - 1;
        while i < n && nums[i - 1] > nums[i] {
            i += 1;
        }

        let q = i -1;
        while i < n && nums[i - 1] < nums[i] {
            i += 1;
        }

        let flag = i - 1;
        p != 0 && q != p && flag == n - 1 && flag != q
    }
}
