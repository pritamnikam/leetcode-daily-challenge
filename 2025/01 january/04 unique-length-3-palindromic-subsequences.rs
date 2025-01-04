// 1930. unique-length-3-palindromic-subsequences
// https://leetcode.com/problems/unique-length-3-palindromic-subsequences

use std::collections::HashSet;

impl Solution {
    pub fn count_palindromic_subsequence(s: String) -> i32 {
        let mut l = [usize::MAX; 26];
        let mut r = [usize::MIN; 26];

        for (i, cr) in s.bytes().enumerate() {
            let c = (cr - b'a') as usize;
            l[c] = usize::min(l[c], i);
            r[c] = usize::max(r[c], i);
        }

        let mut res = 0;
        for cr in b'a'..=b'z' {
            let c = (cr - b'a') as usize;
            if l[c] < r[c] {
                let t: HashSet<u8> = HashSet::from_iter(s[l[c] + 1..r[c]].bytes());
                res += t.len() as i32;
            }
        }
        res
    }
}
