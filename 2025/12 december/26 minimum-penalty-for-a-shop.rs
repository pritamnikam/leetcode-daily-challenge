// minimum-penalty-for-a-shop
// https://leetcode.com/problems/minimum-penalty-for-a-shop

use std::iter::once;
impl Solution {
    pub fn best_closing_time(customers: String) -> i32 {
        (0..).zip(customers.bytes().chain(once(b'N')))
             .scan(0, |penalty, (hour, b)| {
                let cur_penalty = *penalty;
                if b == b'N' { *penalty += 1; } 
                else         { *penalty -= 1; }
                Some((cur_penalty, hour))
             })
             .min()
             .unwrap().1
    }
}
