// 1399. count-largest-group
// https://leetcode.com/problems/count-largest-group

use std::collections::HashMap;

impl Solution {
    pub fn count_largest_group(n: i32) -> i32 {
        let mut hash_map = HashMap::new();
        let mut max_value = 0;
        for i in 1..=n {
            let mut key = 0;
            let mut i0 = i;
            while i0 > 0 {
                key += i0 % 10;
                i0 /= 10;
            }
            *hash_map.entry(key).or_insert(0) += 1;
            max_value = max_value.max(*hash_map.get(&key).unwrap());
        }

        let mut count = 0;
        for &value in hash_map.values() {
            if value == max_value {
                count += 1;
            }
        }
        count
    }
}
