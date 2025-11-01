// 3289. the-two-sneaky-numbers-of-digitville
// https://leetcode.com/problems/the-two-sneaky-numbers-of-digitville
impl Solution {
    pub fn get_sneaky_numbers(nums: Vec<i32>) -> Vec<i32> {
        let n = nums.len() as i32 - 2;
        let mut y = 0;
        // xor all nubers
        for &x in &nums {
            y ^= x;
        }
        // xor numbers between 0-n-2
        for i in 0..n {
            y ^= i;
        }
        // get the low bit of two numbers
        let low_bit = y & -y;
        let mut x1 = 0;
        let mut x2 = 0;

        // using this bit divide into two groups
        // nums into one
        // 0..n-1 into another
        for &x in &nums {
            if x & low_bit != 0 {
                x1 ^= x;
            } else {
                x2 ^= x;
            }
        }
        for i in 0..n {
            if i & low_bit != 0 {
                x1 ^= i;
            } else {
                x2 ^= i;
            }
        }
        // result 
        vec![x1, x2]
    }
}
