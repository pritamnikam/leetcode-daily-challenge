// 838. push-dominoes
// https://leetcode.com/problems/push-dominoes

use std::cmp::Ordering;

impl Solution {
    pub fn push_dominoes(dominoes: String) -> String {
        let n = dominoes.len();
        let mut ste: Vec<i32> = vec![0; n];
        let mut cur: i32 = 0;

        // left to right
        for (idx, c) in dominoes.char_indices() {
            match c {
                'R' => cur = i32::MAX,
                'L' => cur = 0,
                _ => cur = i32::max(0, cur - 1)
            }
            ste[idx] = cur
        }

        cur = 0;
        // right to left
        for (idx, c) in dominoes.char_indices().rev() {
            match c {
                'L' => cur = i32::MAX,
                'R' => cur = 0,
                _ => cur = i32::max(0, cur - 1)
            }

            ste[idx] -= cur
        }

        ste.iter()
            .map(|&x| match x.cmp(&0) {
                Ordering::Less => 'L',
                Ordering::Greater => 'R',
                Ordering::Equal => '.',
            })
            .collect()
    }
}
