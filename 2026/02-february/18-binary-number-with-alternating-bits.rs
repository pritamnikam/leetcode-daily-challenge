// binary-number-with-alternating-bits
// https://leetcode.com/problems/binary-number-with-alternating-bits

impl Solution {
    pub fn has_alternating_bits(n: i32) -> bool {
        (n & (n >> 1)) == 0 && (n | (n >> 2)) == n
    }
}
