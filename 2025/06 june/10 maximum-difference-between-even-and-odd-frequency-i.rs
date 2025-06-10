// 3442. maximum-difference-between-even-and-odd-frequency-i
// https://leetcode.com/problems/maximum-difference-between-even-and-odd-frequency-i

use std::collections::HashMap;

impl Solution {
    pub fn max_difference(s: String) -> i32 {
        let mut c = HashMap::new();
        for ch in s.chars() {
            *c.entry(ch).or_insert(0) += 1;
        }

        let mut maxOdd = 1;
        let mut minEven = s.len() as i32;

        for &value in c.values() {
            if value % 2 == 1 {
                maxOdd = maxOdd.max(value);
            } else {
                minEven = minEven.min(value);
            }
        }

        (maxOdd - minEven) as i32
    }
}
