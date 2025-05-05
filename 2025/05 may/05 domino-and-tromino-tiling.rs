// 790. domino-and-tromino-tiling
// https://leetcode.com/problems/domino-and-tromino-tiling
impl Solution {
    pub fn num_tilings(n: i32) -> i32 {
        (0..n).fold([-1, 0, 1], |v, _| {
            [v[1], v[2], ((v[2] << 1) % 1000000007 + v[0]) % 1000000007]
        })[2]
    }
}
