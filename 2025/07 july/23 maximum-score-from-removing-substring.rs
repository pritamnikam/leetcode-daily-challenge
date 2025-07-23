// 1717. maximum-score-from-removing-substring
// https://leetcode.com/problems/maximum-score-from-removing-substring

use std::cmp::min;

impl Solution {
    pub fn maximum_gain(s: String, x: i32, y: i32) -> i32 {
        let mut total: i32 = 0;

        let mut ac: i32 = 0;
        let mut bc: i32 = 0;

        for ch in s.chars() {
            if ch != 'a' && ch != 'b' {
                total += min(ac, bc) * min(x, y);

                ac = 0;
                bc = 0;

                continue;
            }

            if x > y && ac > 0 {
                if ch == 'b' {
                    ac -= 1;
                    total += x;
                } else {
                    ac += 1;
                }
            } else if y > x && bc > 0 {
                if ch == 'a' {
                    bc -= 1;
                    total += y;
                } else {
                    bc += 1;
                }
            } else {
                if ch == 'a' {
                    ac += 1;
                } else {
                    bc += 1;
                }
            }
        }

        total + min(ac, bc) * min(x, y)
    }
}
