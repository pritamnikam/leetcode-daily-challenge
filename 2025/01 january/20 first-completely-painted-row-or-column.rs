// 2661. first-completely-painted-row-or-column
// https://leetcode.com/problems/first-completely-painted-row-or-column/

use std::collections::HashMap;

impl Solution {
    pub fn first_complete_index(arr: Vec<i32>, mat: Vec<Vec<i32>>) -> i32 {
        let (m, n) = (mat.len(), mat[0].len());

        // map each number to its (row, col) position
        let mut pos: HashMap<i32, (usize, usize)> = HashMap::new();
        for i in 0..m {
            for j in 0..n {
                pos.insert(mat[i][j], (i, j));
            }
        }

        // track the printed cell counts for each row & col
        let mut row_count = vec![0; m];
        let mut col_count = vec![0; n];

        // process array
        for (i, &num) in arr.iter().enumerate() {
            if let Some(&(r,c)) = pos.get(&num){
                row_count[r] += 1;
                col_count[c] += 1;

                // if an entire row or col is painted return ith index
                if row_count[r] == n || col_count[c] == m {
                    return i as i32;
                } 
            }
        }
        
        -1 as i32
    }
}
