// best-time-to-buy-and-sell-stock-v
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-v

use std::cmp::max;

impl Solution {
    pub fn maximum_profit(prices: Vec<i32>, k: i32) -> i64 {
        let n = prices.len();
        let k = k as usize;
        let mut dp = vec![vec![0_i64; 3]; k + 1];
        for j in 1..=k {
            dp[j][1] = -(prices[0] as i64);
            dp[j][2] = prices[0] as i64; 
        }
        
        for i in 1..n {
            for j in (1..=k).rev() {
                dp[j][0] = dp[j][0]
                    .max(dp[j][1] + prices[i] as i64)
                    .max(dp[j][2] - prices[i] as i64);
                dp[j][1] = dp[j][1].max(dp[j - 1][0] - prices[i] as i64);
                dp[j][2] = dp[j][2].max(dp[j - 1][0] + prices[i] as i64);
            }
        }
        
        dp[k][0]
    }
}
