// binary-gap
// https://leetcode.com/problems/binary-gap

impl Solution {
    pub fn binary_gap(n: i32) -> i32 {
        let mut result = 0;
        let mut last1 = -100;
        let mut n = n;

        while n > 0 {
            result = result.max(last1);
            last1 = last1 * (n & 1 ^ 1) + 1;
            n = n >> 1;
        }
        result
    }
}
