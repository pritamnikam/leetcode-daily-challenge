// divide-an-array-into-subarrays-with-minimum-cost-i
// https://leetcode.com/problems/divide-an-array-into-subarrays-with-minimum-cost-i

use std::{cmp::Reverse, collections::BinaryHeap};

impl Solution {
    #[allow(dead_code)]
    pub fn minimum_cost(nums: Vec<i32>) -> i32 {

        let mut heap = nums.iter().enumerate().fold(BinaryHeap::new(), |mut arr, (i, x)| {
            if i != 0 {
                arr.push(Reverse(x));
            }
            arr
        });
        
        nums[0] 
        + heap.pop().unwrap().0 
        + heap.pop().unwrap().0
    }
}
