// the-k-th-lexicographical-string-of-all-happy-strings-of-length-n
// https://leetcode.com/problems/the-k-th-lexicographical-string-of-all-happy-strings-of-length-n

impl Solution {
    pub fn get_happy_string(n: i32, mut k: i32) -> String {
        let mut ans = String::new();
        Self::backtrack(
            n as usize, 
            &mut k,
            &mut Vec::new(), 
            &mut ans
        );
        ans
    }

    fn backtrack(
        n: usize, k: &mut i32, cur: &mut Vec<u8>, ans: &mut String
    ) {
        if n == 0 {
            *k -= 1;
            if *k == 0 { *ans = String::from_utf8(cur.clone() as Vec<u8>).unwrap() }
            return;
        }
        for letter in [b'a', b'b', b'c'] {
            if !cur.is_empty() && *cur.last().unwrap() == letter { continue }
            if *k == 0 { break; }

            cur.push(letter);
            Self::backtrack(n - 1, k, cur, ans);
            cur.pop();
        }
    }
}
