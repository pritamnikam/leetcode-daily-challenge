// 3330. find-the-original-typed-string-i
// https://leetcode.com/problems/find-the-original-typed-string-i

impl Solution {
    pub fn possible_string_count(word: String) -> i32 {
        let mut ans = 1;
        let chars: Vec<char> = word.chars().collect();
        for i in 1..chars.len() {
            if chars[i-1] == chars[i] {
                ans+=1;
            }
        }
        ans
    }
}
