// 2017. grid-game
// https://leetcode.com/problems/grid-game/

impl Solution {
    pub fn grid_game(grid: Vec<Vec<i32>>) -> i64 {
        let mut sum1: i64 = (grid[0].iter().map(|&i| i as i64).sum::<i64>() - grid[0][0] as i64);
        let mut sum2: i64 = 0;
        let mut result = sum1;
        for i in 0..grid[0].len() - 1 {
            sum1 -= grid[0][i + 1] as i64;
            sum2 += grid[1][i] as i64;
            result = result.min(sum1.max(sum2));
        }
        result
    }
}
