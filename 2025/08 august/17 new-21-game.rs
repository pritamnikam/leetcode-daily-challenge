// 837. new-21-game
// https://leetcode.com/problems/new-21-game

impl Solution {
    pub fn new21_game(n: i32, k: i32, max_pts: i32) -> f64 {
        if k == 0 || n >= k - 1 + max_pts {
            return 1.0;
        }
        let n = n as usize;
        let k = k as usize;
        let max_pts = max_pts as usize;
        let mut dp = vec![0.0; n + 1];
        dp[0] = 1.0;
        let mut window_sum = 1.0;
        let mut probability = 0.0;
        for i in 1..=n {
            dp[i] = window_sum / max_pts as f64;
            if i < k {
                window_sum += dp[i];
            } else {
                probability += dp[i];
            }
            if i >= max_pts {
                window_sum -= dp[i - max_pts];
            }
        }
        probability
    }
}
