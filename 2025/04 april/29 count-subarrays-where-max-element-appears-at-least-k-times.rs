// 2962. count-subarrays-where-max-element-appears-at-least-k-times
// https://leetcode.com/problems/count-subarrays-where-max-element-appears-at-least-k-times

impl Solution {
    pub fn count_subarrays(nums: Vec<i32>, k: i32) -> i64 {
        let max = *nums.iter().max().unwrap();
        let (mut left, mut count, mut res) = (0, 0, 0 as i64);

        for val in nums.iter() {
            if *val == max {
                count += 1;
            }

            while count >= k {
                if (nums[left] == max) {
                    count -= 1;
                }
                left += 1;
            }

            res += left as i64;
        }
        res
    }
}
