// 2402. meeting-rooms-iii
// https://leetcode.com/problems/meeting-rooms-iii/

use std::collections::BinaryHeap;
use std::cmp::Reverse;
impl Solution {
    pub fn most_booked(n: i32, mut meetings: Vec<Vec<i32>>) -> i32 {
        meetings.sort_unstable();
        let mut mts: BinaryHeap<Reverse<(i64, i32)>> = BinaryHeap::new();
        let mut rms = (0..n).map(|v| Reverse(v)).collect::<BinaryHeap<_>>();
        let mut cnt = vec![0; n as usize];
        
        for meeting in &meetings {
            let mut off = 0i64;
            while !mts.is_empty() && mts.peek().unwrap().0.0 <= meeting[0] as i64 {
                rms.push(Reverse(mts.pop().unwrap().0.1));
            }
            let mut r = if let Some(r) = rms.pop() {
                r.0
            } else {
                let p = mts.pop().unwrap().0;
                off = p.0 - meeting[0] as i64;
                p.1
            };
            cnt[r as usize] += 1;
            mts.push(Reverse((off + meeting[1] as i64, r)));
        }
		// the max function by deafult returns the last max element if there is a tie.
        cnt.iter().enumerate().max_by_key(|(idx, &c)| (c, n as usize - idx)).unwrap().0 as i32 
    }
}
