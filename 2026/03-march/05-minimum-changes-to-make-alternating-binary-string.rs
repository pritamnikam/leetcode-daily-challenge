// minimum-changes-to-make-alternating-binary-string
// https://leetcode.com/problems/minimum-changes-to-make-alternating-binary-string

impl Solution {
    pub fn min_operations(s: String) -> i32 {
        s.bytes()
            .zip((0..2).cycle())
            .fold([0, 0], |mut zo, (b, x)| {
                zo[(b & 1 ^ x) as usize] += 1;
                zo
            })
            .into_iter()
            .fold(i32::MAX, i32::min)
    }
}
