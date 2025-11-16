// 1513. number-of-substrings-with-only-1s
// https://leetcode.com/problems/number-of-substrings-with-only-1s

impl Solution {
    pub fn num_sub(s: String) -> i32 {
        const MODULO: i64 = 1000000007;
        let mut total: i64 = 0;
        let mut consecutive: i64 = 0;
        for c in s.chars() {
            if c == '0' {
                total += consecutive * (consecutive + 1) / 2;
                total %= MODULO;
                consecutive = 0;
            } else {
                consecutive += 1;
            }
        }
        total += consecutive * (consecutive + 1) / 2;
        total %= MODULO;
        total as i32
    }
}
