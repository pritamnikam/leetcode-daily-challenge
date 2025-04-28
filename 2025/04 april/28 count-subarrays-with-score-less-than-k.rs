// 2302. count-subarrays-with-score-less-than-k
// https://leetcode.com/problems/count-subarrays-with-score-less-than-k

impl Solution {
    pub fn count_subarrays(nums: Vec<i32>, k: i64) -> i64 {
        let (n, mut res, mut total, mut i) = (nums.len(), 0, 0, 0);
        for j in 0..n {
            total += nums[j] as i64;
            while i <= j && total * (j - i + 1) as i64 >= k {
                total -= nums[i] as i64;
                i += 1;
            }
            res += j - i + 1;
        }
        res as i64
    }
}
