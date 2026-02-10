// longest-balanced-subarray-i
// https://leetcode.com/problems/longest-balanced-subarray-i/

use std::cmp::max;
use std::collections::HashMap;

impl Solution {
    pub fn longest_balanced(nums: Vec<i32>) -> i32 {
        let n = nums.len();
        let mut mx = 0;

        for len in (1..=n).rev() {
            let mut e: HashMap<i32, usize> = HashMap::new();
            let mut o: HashMap<i32, usize> = HashMap::new();

            // init
            for i in 0..len {
                let x = nums[i];
                if x % 2 == 0 {
                    *e.entry(x).or_insert(0) += 1;
                } else {
                    *o.entry(x).or_insert(0) += 1;
                }
            }

            if e.len() == o.len() {
                mx = max(mx, len);
            }

            for i in 0..(n - len) {
                let l = nums[i];
                let r = nums[i + len];

                // update (L)
                if l % 2 == 0 {
                    let v = e.get_mut(&l).expect("number on the left");
                    if *v == 1 {
                        e.remove(&l);
                    } else {
                        *v -= 1;
                    }
                } else {
                    let v = o.get_mut(&l).expect("number on the left");
                    if *v == 1 {
                        o.remove(&l);
                    } else {
                        *v -= 1;
                    }
                }
                // update (R)
                if r % 2 == 0 {
                    *e.entry(r).or_insert(0) += 1;
                } else {
                    *o.entry(r).or_insert(0) += 1;
                }

                if e.len() == o.len() {
                    mx = max(mx, len);
                }

            }
        }

        mx as i32
    }
}
