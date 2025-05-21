// 73. set-matrix-zeroes
// https://leetcode.com/problems/set-matrix-zeroes

use std::collections::HashSet;
impl Solution {
    pub fn set_zeroes(matrix: &mut [Vec<i32>]) {
        let (rows, cols): (HashSet<_>, HashSet<_>) = (0..matrix.len())
            .flat_map(|row| (0..matrix[0].len()).map(move |x| (row, x)))
            .filter(|(y, x)| matrix[*y][*x] == 0)
            .collect();
        for row in rows {
            matrix[row].iter_mut().for_each(|cell| *cell = 0);
        }
        for col in cols {
            matrix.iter_mut().for_each(|row| row[col] = 0);
        }
    }
}
