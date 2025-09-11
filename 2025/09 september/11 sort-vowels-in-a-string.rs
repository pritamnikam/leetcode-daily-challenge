// 2785. sort-vowels-in-a-string
// https://leetcode.com/problems/sort-vowels-in-a-string

use std::collections::HashSet;

impl Solution {
    pub fn sort_vowels(s: String) -> String {
        let vowels = HashSet::from(
            ['a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U' ]
        );
        let mut all_vowels: Vec<_> = s.chars().filter(|c| vowels.contains(&c)).collect();
        all_vowels.sort_unstable();

        let (mut pos, mut res) = (0, String::with_capacity(s.len()));
        for c in s.chars() {
            if vowels.contains(&c) {
                res.push(all_vowels[pos]);
                pos += 1;
            } else {
                res.push(c);
            }
        }
        res
    }
}
