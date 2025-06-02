// 135. candy
// https://leetcode.com/problems/candy

use std::cmp::{self, Ordering};
impl Solution {

pub fn candy(ratings: Vec<i32>) -> i32 {
        ratings
        .windows(2)
        .map(|x| x[0].cmp(&x[1]))
        .fold((1, 1, 1, 0), |(res, front, top, dec_count): (i32, i32, i32, i32), x| {
           match x {
            Ordering::Greater => {
                if top <= dec_count + 1 {
                    (res + dec_count + 1 + 1, 1, top + 1, dec_count + 1)
                } else {
                    (res + dec_count + 1, 1, top, dec_count + 1)
                }
            },
            Ordering::Equal => {
                (res + 1, 1, 1, 0)
            },
            Ordering::Less => {
                (res + front + 1, front + 1, front + 1, 0)
            }
           } 
        })
        .0
    }
}
