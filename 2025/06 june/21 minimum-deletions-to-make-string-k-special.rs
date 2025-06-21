// 3085. minimum-deletions-to-make-string-k-special
// https://leetcode.com/problems/minimum-deletions-to-make-string-k-special

use std::collections::HashMap;
impl Solution {
    pub fn minimum_deletions(word: String, k: i32) -> i32 {
        let mut cnt = HashMap::new();
        for c in word.chars() {
            *cnt.entry(c).or_insert(0) += 1;
        }
        let mut res = word.len() as i32;
        for &a in cnt.values() {
            let mut deleted = 0;
            for &b in cnt.values() {
                if a > b {
                    deleted += b;
                } else if b > a + k {
                    deleted += b - (a + k);
                }
            }
            res = res.min(deleted);
        }
        res
    }
}
