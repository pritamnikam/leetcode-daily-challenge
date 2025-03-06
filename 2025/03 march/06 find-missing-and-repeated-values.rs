// 2965. find-missing-and-repeated-values
// https://leetcode.com/problems/find-missing-and-repeated-values/

impl Solution {
    pub fn find_missing_and_repeated_values(grid: Vec<Vec<i32>>) -> Vec<i32> {
        let n_sq = grid.len() * grid.len();
        let total = n_sq * (n_sq + 1) / 2;
        let total_sq = n_sq * (n_sq + 1) * (2 * n_sq + 1) / 6;

        let diff = total as i32 - grid.iter().flatten().sum::<i32>();
        let diff_sq = total_sq as i32 - grid.iter().flatten().map(|x| x * x).sum::<i32>();

        let b = (diff + diff_sq / diff) / 2;
        let a = b - diff;

        vec![a, b]
    }
}
