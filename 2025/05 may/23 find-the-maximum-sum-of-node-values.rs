// 3068. find-the-maximum-sum-of-node-values
// https://leetcode.com/problems/find-the-maximum-sum-of-node-values

impl Solution {
    pub fn maximum_value_sum(nums: Vec<i32>, k: i32, _edges: Vec<Vec<i32>>) -> i64 {
        let n = nums.len();
        let mut dp = vec![[0i64; 2]; n + 1];
        dp[n][0] = i64::MIN;
        dp[n][1] = 0;
        for i in (0..n).rev() {
            for s in 0..2 {
                let no_xor = nums[i] as i64 + dp[i + 1][s];
                let xor_done = ((nums[i] ^ k) as i64) + dp[i + 1][s ^ 1];
                dp[i][s] = no_xor.max(xor_done);
            }
        }
        dp[0][1]
    }
}
