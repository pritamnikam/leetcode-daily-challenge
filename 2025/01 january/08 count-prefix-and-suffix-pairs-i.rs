// 3042. count-prefix-and-suffix-pairs-i
// https://leetcode.com/problems/count-prefix-and-suffix-pairs-i/
impl Solution {
    pub fn count_prefix_suffix_pairs(words: Vec<String>) -> i32 {
        fn is_prefix_and_suffix(str1: &str, str2: &str) -> bool {
            str2.starts_with(str1) && str2.ends_with(str1)
        }

        let mut count  = 0;
        for i in 0..words.len() {
            for j in (i+1)..words.len() {
                if (is_prefix_and_suffix(&words[i], &words[j])) {
                    count += 1;
                }
            }
        }
        count
    }
}
