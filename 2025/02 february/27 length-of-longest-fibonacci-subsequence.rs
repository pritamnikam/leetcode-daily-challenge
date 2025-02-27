// 837. length-of-longest-fibonacci-subsequence
// https://leetcode.com/problems/length-of-longest-fibonacci-subsequence/

use std::collections::*;

impl Solution {
    pub fn len_longest_fib_subseq(arr: Vec<i32>) -> i32 {
        let n = arr.len();
        let mut result = 0;
        let mut set = HashSet::new();

        for i in 0..n {
            set.insert(arr[i]);
        }


        for i in 0..n {
            let bv1 = arr[i];
            for j in i+1..n {
                let mut v1 = bv1;
                let mut v2 = arr[j];

                let mut count = 0;

                while set.contains(&(v1 + v2)) {
                    count += 1;
                    let nv = v1+v2;
                    v1 = v2;
                    v2 = nv;
                }

                if 0 < count {
                    result = result.max(count + 2);
                }
            }
        }
        result
    }
}
