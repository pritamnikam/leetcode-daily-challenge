// 2460. apply-operations-to-an-array
// https://leetcode.com/problems/apply-operations-to-an-array/

impl Solution {
    pub fn apply_operations(mut nums: Vec<i32>) -> Vec<i32> {
        let n = nums.len();
        for i in 0..n-1 {
            if nums[i] == nums[i + 1] {
                nums[i] *= 2;
                nums[i + 1] = 0;
            }
        }

        let mut non_zero_idx = 0;

        for i in 0..n {
            if nums[i] != 0 {
                nums[non_zero_idx] = nums[i];
                non_zero_idx += 1;
            }
        }

        for i in non_zero_idx..n {
            nums[i] = 0;
        }
        nums
    }
}
