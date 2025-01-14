// 2657. find-the-prefix-common-array-of-two-arrays
// https://leetcode.com/problems/find-the-prefix-common-array-of-two-arrays/

use std::collections::HashSet;

impl Solution {
    pub fn find_the_prefix_common_array(a: Vec<i32>, b: Vec<i32>) -> Vec<i32> {
        let n = a.len();
        let mut seen_in_A = HashSet::new();
        let mut seen_in_B = HashSet::new();
        let mut result = Vec::new();

        for i in 0..n {
            seen_in_A.insert(a[i]);
            seen_in_B.insert(b[i]);


            // computer intersection
            let common_count = seen_in_A.intersection(&seen_in_B).count() as i32;
            result.push(common_count);
        }

        result
    }
}
