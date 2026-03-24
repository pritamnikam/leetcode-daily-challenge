// construct-product-matrix
// https://leetcode.com/problems/construct-product-matrix

impl Solution {
    pub fn construct_product_matrix(grid: Vec<Vec<i32>>) -> Vec<Vec<i32>> {
        const MOD: i64 = 12345;

        let n = grid.len();
        let m = grid[0].len();
        let mut p = vec![vec![0; m]; n];

        let mut suffix: i64 = 1;
        for i in (0..n).rev() {
            for j in (0..m).rev() {
                p[i][j] = (suffix % MOD) as i32;
                suffix = (suffix * grid[i][j] as i64) % MOD;
            }
        }

        let mut prefix: i64 = 1;
        for i in 0..n {
            for j in 0..m {
                p[i][j] = ((p[i][j] as i64 * prefix) % MOD) as i32;
                prefix = (prefix * grid[i][j] as i64) % MOD;
            }
        }
        p
    }
}
