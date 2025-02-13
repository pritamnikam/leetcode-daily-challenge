// 3066. minimum-operations-to-exceed-threshold-value-ii
// https://leetcode.com/problems/minimum-operations-to-exceed-threshold-value-ii/

use std::cmp::Reverse;
use std::collections::BinaryHeap;
impl Solution {
    pub fn min_operations(nums: Vec<i32>, k: i32) -> i32 {
        let (k, mut ans) = (k as i64, 0);
        let mut queue = nums.into_iter()
                            .map(|num| Reverse(num as i64))
                            .collect::<BinaryHeap<_>>();

        while queue.peek().unwrap().0 < k {
            ans += 1;
            let n1 = queue.pop().unwrap().0;
            let n2 = queue.pop().unwrap().0;
            queue.push(Reverse(n1 * 2 + n2));
        }

        ans
    }
}
