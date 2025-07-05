// 1394. find-lucky-integer-in-an-array
// https://leetcode.com/problems/find-lucky-integer-in-an-array

use itertools::Itertools;

impl Solution {
    pub fn find_lucky(arr: Vec<i32>) -> i32 {
        arr.iter()
            .counts()
            .into_iter()
            .filter(|(k, v)| **k == *v as i32)
            .map(|(k, _)| *k)
            .max()
            .unwrap_or(-1)
    }
}
