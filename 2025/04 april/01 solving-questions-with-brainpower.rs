// 2140. solving-questions-with-brainpower
// https://leetcode.com/problems/solving-questions-with-brainpower

impl Solution {
    pub fn most_points(questions: Vec<Vec<i32>>) -> i64 {
        let n = questions.len();
        let mut dp = vec![0; n + 1];

        for i in (0..n).rev() {
            let points = questions[i][0] as i64;
            let brainpower = questions[i][1] as usize;
            let next_question = i + brainpower + 1;

            let solve = points + if next_question < n { dp[next_question] } else { 0 };
            let skip = dp[i + 1];

            dp[i] = solve.max(skip);
        }
        dp[0]
    }
}
