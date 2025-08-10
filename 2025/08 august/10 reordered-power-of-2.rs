// 869. reordered-power-of-2
// https://leetcode.com/problems/reordered-power-of-2

use std::collections::*;

impl Solution {
    pub fn reordered_power_of2(n: i32) -> bool {
        let mut set = HashSet::new();
        let num_2_set = |mut n: i32| -> Vec<i32> {
            let mut v = Vec::with_capacity(10);
            while n > 0 {
                v.push(n % 10);
                n /= 10;
            }

            v.sort();
            v
        };

        for i in 0..31 {
            set.insert(
                num_2_set(1 << i)
            );
        }

        set.contains(&(num_2_set(n)))
    }
}
