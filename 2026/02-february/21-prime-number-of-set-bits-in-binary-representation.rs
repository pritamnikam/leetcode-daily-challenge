// prime-number-of-set-bits-in-binary-representation
// https://leetcode.com/problems/prime-number-of-set-bits-in-binary-representation

impl Solution {
    pub fn count_prime_set_bits(left: i32, right: i32) -> i32 {

        (left..=right).fold(0i32, |acc, x| {
            acc + match x.count_ones() {
                2 | 3 | 5 | 7 | 11 | 13 | 17 | 19 | 23 | 29 | 31 => 1,
                _ => 0,
            }
        })
    }
}
