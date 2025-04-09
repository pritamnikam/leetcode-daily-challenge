// 3375. minimum-operations-to-make-array-values-equal-to-k
// https://leetcode.com/problems/minimum-operations-to-make-array-values-equal-to-k

use std::collections::HashSet;

impl Solution {

    pub fn min_operations(nums: Vec<i32>, k: i32) -> i32 {
        let mut st = HashSet::new();
        for x in nums {
            if x < k {
                return -1
            } else if x > k {
                st.insert(x);
            }
        }
        st.len() as i32
    }
}
