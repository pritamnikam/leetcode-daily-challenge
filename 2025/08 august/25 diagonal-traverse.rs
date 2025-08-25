// 498. diagonal-traverse
// https://leetcode.com/problems/diagonal-traverse

impl Solution {
    pub fn find_diagonal_order(mat: Vec<Vec<i32>>) -> Vec<i32> {
        let (m, n, mut r, mut c, mut d) = (mat.len() as i32, mat[0].len() as i32, 0, 0, 1); 
        let mut ans = Vec::new();

        for _ in 0..(m * n) {
            ans.push(
                mat[r as usize][c as usize]
            );

            r -= d; c += d;

            if r < 0 || r == m || c < 0 || c == n {
                if r == m { r = m - 1; c -= d - 1; }
                if c == n { c = n - 1; r += d + 1; }
                if r < 0 { r = 0; }
                if c < 0 { c = 0; }

                d = -d;
            }
        }
        ans
    }
}
