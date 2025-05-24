// 2942. find-words-containing-character
// https://leetcode.com/problems/find-words-containing-character

impl Solution {
    pub fn find_words_containing(words: Vec<String>, x: char) -> Vec<i32> {
        let mut res = Vec::new();
        let n = words.len();

        for i in 0..n {
            if words[i].contains(x) {
                res.push(i as i32)
            }
        }
        res
    }
}
