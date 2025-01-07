// 1408. string-matching-in-an-array
// https://leetcode.com/problems/string-matching-in-an-array/

use std::collections::HashSet;

impl Solution {
    pub fn string_matching(words: Vec<String>) -> Vec<String> {
        let mut substrings = HashSet::new();

        for i in 0..words.len() {
            for j in 0..words.len() {
                if i != j && words[j].contains(&words[i]) {
                    substrings.insert(words[i].clone());
                }
            }
        }
        substrings.into_iter().collect()

    }
}
