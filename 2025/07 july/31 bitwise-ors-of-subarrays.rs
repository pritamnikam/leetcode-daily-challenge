// 898. bitwise-ors-of-subarrays
// https://leetcode.com/problems/bitwise-ors-of-subarrays

use std::collections::HashSet;

impl Solution {
    pub fn subarray_bitwise_o_rs(arr: Vec<i32>) -> i32 {
        let mut unique = HashSet::new();
        let mut prev = HashSet::new();

        for &num in arr.iter() {
            let mut curr_p = HashSet::from([num]);
            unique.insert(num);

            for num2 in prev.iter() {
                let curr = num | num2;
                unique.insert(curr);
                curr_p.insert(curr);
            }

            prev = curr_p;
        }

        unique.len() as i32
    }
}
