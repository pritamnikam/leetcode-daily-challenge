// divide-an-array-into-subarrays-with-minimum-cost-ii
// https://leetcode.com/problems/divide-an-array-into-subarrays-with-minimum-cost-ii

use std::collections::BTreeSet;
impl Solution {
    pub fn minimum_cost(nums: Vec<i32>, k: i32, dist: i32) -> i64 {
        let n = nums.len();
        let k = k as usize;
        let dist = dist as usize;
        let mut min_sum = i64::MAX;
        let mut max_heap = BTreeSet::<(i32, usize)>::new();
        let mut min_heap = BTreeSet::<(i32, usize)>::new();
        let mut curr_sum = 0i64;
        // println!("{nums:?}");
        for i in 1..n {
            if max_heap.len() < k - 1 || nums[i] < max_heap.last().unwrap().0 {
                max_heap.insert((nums[i], i));
                curr_sum += nums[i] as i64;
                if max_heap.len() == k {
                    let num = max_heap.pop_last().unwrap();
                    curr_sum -= num.0 as i64;
                    min_heap.insert(num);
                }
            } else {
                min_heap.insert((nums[i], i));
            }
            // println!("I: {i}\nMax: {max_heap:?}\nMin: {min_heap:?}");
            if max_heap.len() >= k - 1 {
                min_sum = std::cmp::min(min_sum, curr_sum);
            }
            if i - 1 >= dist {
                let num = (nums[i - dist], i - dist);
                if max_heap.contains(&num) {
                    curr_sum -= num.0 as i64;
                    max_heap.remove(&num);
                    if !min_heap.is_empty() {
                        let p_num = min_heap.pop_first().unwrap();
                        curr_sum += p_num.0 as i64;
                        max_heap.insert(p_num);
                    }
                } else {
                    min_heap.remove(&num);
                }
            }
        }
        nums[0] as i64 + min_sum
    }
}
