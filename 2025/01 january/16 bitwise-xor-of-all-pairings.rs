// 2425. bitwise-xor-of-all-pairings
// https://leetcode.com/problems/bitwise-xor-of-all-pairings

impl Solution {
    pub fn xor_all_nums(nums1: Vec<i32>, nums2: Vec<i32>) -> i32 {
        let mut result = 0;

        if nums1.len() % 2 != 0 {
            for &num in &nums2 {
                result ^= num;
            }
        }

        if nums2.len() % 2 != 0 {
            for &num in &nums1 {
                result ^= num
            }
        }

        result
    }
}
