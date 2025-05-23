// count-the-number-of-good-subarrays
// https://leetcode.com/problems/count-the-number-of-good-subarrays

use std::collections::HashMap;

impl Solution {
    pub fn count_good(nums: Vec<i32>, k: i32) -> i64 {
        let n = nums.len();
        let mut same = 0;
        let mut right = -1;
        let mut cnt = HashMap::new();
        let mut ans = 0i64;
        for left in 0..n {
            while same < k && right + 1 < n as i32 {
                right += 1;
                let num = nums[right as usize];
                same += *cnt.get(&num).unwrap_or(&0);
                *cnt.entry(num).or_insert(0) += 1;
            }
            if same >= k {
                ans += (n as i64) - (right as i64);
            }
            let num = nums[left];
            *cnt.entry(num).or_insert(0) -= 1;
            same -= *cnt.get(&num).unwrap_or(&0);
        }
        ans
    }
}
