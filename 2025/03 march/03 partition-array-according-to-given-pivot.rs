// 2161. partition-array-according-to-given-pivot
// https://leetcode.com/problems/partition-array-according-to-given-pivot/

use std::cmp::Ordering::{Less, Equal, Greater};

impl Solution {
    pub fn pivot_array(nums: Vec<i32>, pivot: i32) -> Vec<i32> {
        let n = nums.len();
        let (mut l, mut e, mut g) = (
            Vec::with_capacity(n),
            Vec::with_capacity(n),
            Vec::with_capacity(n)
        );

        for el in nums.into_iter() {
            match el.cmp(&pivot) {
                Less => { l.push(el) },
                Equal => { e.push(el) },
                Greate => { g.push(el) },
            }
        }

        l.into_iter()
            .chain(e.into_iter())
            .chain(g.into_iter())
            .collect()
    }
}
