// 1780. check-if-number-is-a-sum-of-powers-of-three
// https://leetcode.com/problems/check-if-number-is-a-sum-of-powers-of-three

impl Solution {
    pub fn check_powers_of_three(mut n: i32) -> bool {
        while n > 0 {
            if n % 3 == 2 {
                return false;
            }
            n = n  / 3;
        }
        true
    }
}
