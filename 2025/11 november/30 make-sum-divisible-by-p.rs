// make-sum-divisible-by-p
// https://leetcode.com/problems/make-sum-divisible-by-p

use std::collections::HashMap;

impl Solution {
    pub fn min_subarray(nums: Vec<i32>, p: i32) -> i32 {
        let p = p as i64;
        let mut total: i64 = nums.iter().map(|&x| x as i64).sum();
        let target = total % p;

        if target == 0 {
            return 0;
        }

        let mut map: HashMap<i64, i32> = HashMap::new();
        map.insert(0, -1);

        let mut prefix: i64 = 0;
        let mut res = nums.len() as i32;

        for (i, &x) in nums.iter().enumerate() {
            prefix = (prefix + x as i64) % p;
            let need = (prefix - target + p) % p;

            if let Some(prev) = map.get(&need) {
                res = res.min(i as i32 - *prev);
            }

            map.insert(prefix, i as i32);
        }

        if res == nums.len() as i32 { -1 } else { res }
    }
}
