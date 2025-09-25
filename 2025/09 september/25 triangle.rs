// triangle
// https://leetcode.com/problems/triangle/

impl Solution {
    pub fn minimum_total(triangle: Vec<Vec<i32>>) -> i32 {
        let mut triangle = triangle;
        let n = triangle.len();
        for i in (0..n-1).rev() {
            for j in 0..triangle[i].len() {
                triangle[i][j] += triangle[i+1][j].min(triangle[i+1][j+1]);
            }
        }
        triangle[0][0]
    }
}
