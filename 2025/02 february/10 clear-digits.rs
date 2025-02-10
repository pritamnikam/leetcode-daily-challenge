// 3174. clear-digits
// https://leetcode.com/problems/clear-digits/

impl Solution {
    pub fn clear_digits(mut s: String) -> String {
        s.chars().fold(String::new(), |mut stack, c| {
            if '0' <= c && c <= '9' {
                stack.pop();
            } else {
                stack.push(c);
            }
            stack
        })
    }
}
