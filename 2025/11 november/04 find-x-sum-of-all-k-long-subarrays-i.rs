// 3318. find-x-sum-of-all-k-long-subarrays-i
// https://leetcode.com/problems/find-x-sum-of-all-k-long-subarrays-i/

use std::collections::{BinaryHeap, HashMap};
impl Solution {
    pub fn find_x_sum(nums: Vec<i32>, k: i32, x: i32) -> Vec<i32> {
        let k = k as usize;
        let x = x as usize;

        nums.iter()
            .enumerate()
            .scan(HashMap::<_, usize>::new(), |map, (i, n)| {
                *map.entry(n).or_default() += 1;
                if i >= k {
                    *map.get_mut(&nums[i - k]).unwrap() -= 1;
                }
                Some(map.clone())
            })
            .skip(k-1)
            .map(|counts| {
                counts
                    .into_iter()
                    .map(|(n, count)| (count, *n))
                    .collect::<BinaryHeap<_>>()
                    .into_sorted_vec()
                    .into_iter()
                    .rev()
                    .take(x)
                    .map(|(count, n)| n * count as i32)
                    .sum()
            })
            .collect()
    }
}
