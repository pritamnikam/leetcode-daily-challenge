// minimum-deletions-to-make-string-balanced
// https://leetcode.com/problems/minimum-deletions-to-make-string-balanced

impl Solution {
    pub fn minimum_deletions(s: String) -> i32 {
        let mut b = 0;
        let mut ans = 0;

        for ch in s.bytes() {
            if ch == b'b' {
                b += 1;
            } else {
                ans = (ans + 1).min(b);
            }
        }
        ans
    }
}
