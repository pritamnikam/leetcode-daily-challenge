// 2185. counting-words-with-a-given-prefix
// https://leetcode.com/problems/counting-words-with-a-given-prefix

impl Solution {
    pub fn prefix_count(words: Vec<String>, pref: String) -> i32 {
        fn is_prefix(str1: &str, str2: &str) -> bool {
            str1.starts_with(str2)
        }

        let mut count = 0;
        for i in (0..words.len()) {
            if is_prefix(&words[i], &pref) {
                count += 1;
            }
        }
        count
    }
}
