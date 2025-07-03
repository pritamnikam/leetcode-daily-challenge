// 3304. find-the-k-th-character-in-string-game-i
// https://leetcode.com/problems/find-the-k-th-character-in-string-game-i

impl Solution {
    pub fn kth_character(k: i32) -> char {
        let mut ans = 0;
        let mut k = k;
        while k != 1 {
            let t = 31 - k.leading_zeros();
            let t = if (1 << t) == k { t - 1 } else { t };
            k -= 1 << t;
            ans += 1;
        }
        (b'a' + ans) as char
    }
}
