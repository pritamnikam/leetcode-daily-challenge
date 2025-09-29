// 1039. minimum-score-triangulation-of-polygon
// https://leetcode.com/problems/minimum-score-triangulation-of-polygon

impl Solution {
    pub fn min_score_triangulation(values: Vec<i32>) -> i32 {
        let n = values.len();
        let mut dp = vec![vec![0; n]; n];

        for l in 3..=n {
            for i in 0..n {
                let j = i + l - 1;

                dp[i][j % n] = (i+1..j)
                                    .map(|k| values[i] * values[j % n] * values[k % n] + dp[i][k % n] + dp[k % n][j % n])
                                    .fold(i32::MAX, i32::min);
            }
        }

        (0..n)
            .map(|x| dp[x][(x+n-1)%n])
            .fold(i32::MAX, i32::min)
    }
}
