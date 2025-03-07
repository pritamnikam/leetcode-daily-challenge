// 2523. closest-prime-numbers-in-range
// https://leetcode.com/problems/closest-prime-numbers-in-range/

impl Solution {
    pub fn closest_primes(left: i32, right: i32) -> Vec<i32> {
        let right = right as usize;
        let left = left as usize;
        let mut primes = vec![true; (right + 1) as usize];
        primes[0] = false;
        primes[1] = false;

        for p in 2..=(right as f32 +1.0).sqrt().floor() as usize  {
            if primes[p as usize] {
                for multiple in (p * p..=right).step_by(p as usize) {
                    primes[multiple as usize] = false;
                }
            }
        }
        
        let Some(mut x) = (left..=right).filter(|&i|primes[i]).next() else {return vec![-1,-1]};
        let Some(mut y) = (x+1..=right).filter(|&i|primes[i]).next() else {return vec![-1,-1]};
        let mut best = (y - x, x, y);
        for i in y+1..=right {
            if primes[i] {
                (x, y) = (y, i);
                best = best.min((y-x, x, y));
            }
        }
        vec![best.1 as i32, best.2 as i32]

    }
}
