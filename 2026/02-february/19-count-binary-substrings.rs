// count-binary-substrings
// https://leetcode.com/problems/count-binary-substrings

impl Solution {
    pub fn count_binary_substrings(s: String) -> i32 {
        s.bytes().fold(
            (0, 0, 0, b'_'),
            |(ans, pre, cur, p), c| {
                let [pre, cur] = if p == c { [pre, cur + 1] } else { [cur, 1] };
                (ans + (pre >= cur) as i32, pre, cur, c)
            }
        ).0
    }
}
