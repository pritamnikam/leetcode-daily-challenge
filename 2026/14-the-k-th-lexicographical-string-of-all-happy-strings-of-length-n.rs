// the-k-th-lexicographical-string-of-all-happy-strings-of-length-n
// https://leetcode.com/problems/the-k-th-lexicographical-string-of-all-happy-strings-of-length-n

impl Solution {
    pub fn get_happy_string(n: i32, mut k: i32) -> String {
        let mut s = String::with_capacity(n as usize);
        Self::backtrack(n as usize, &mut k, &mut s);
        s
    }

    fn backtrack(
        n: usize,
        k: &mut i32,
        s: &mut String
    ) {
        if s.len() == n {
            *k -= 1;
            return;
        }

        for ch in 'a'..='c' {
            if s.ends_with(ch) {
                continue;
            }

            s.push(ch);
            Self::backtrack(n, k, s);
            if *k == 0 {
                break;
            }
            s.pop();
        }
    }
}
