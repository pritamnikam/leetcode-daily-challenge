// find-the-minimum-area-to-cover-all-ones-i
// https://leetcode.com/problems/find-the-minimum-area-to-cover-all-ones-i

impl Solution {
    pub fn minimum_area(grid: Vec<Vec<i32>>) -> i32 {
        let n = grid.len();
        let m = grid[0].len();
        let mut min_i = n;
        let mut max_i = 0;
        let mut min_j = m;
        let mut max_j = 0;
        
        for (i, row) in grid.iter().enumerate() {
            for (j, &val) in row.iter().enumerate() {
                if val == 1 {
                    min_i = min_i.min(i);
                    max_i = max_i.max(i);
                    min_j = min_j.min(j);
                    max_j = max_j.max(j);
                }
            }
        }
        
        ((max_i - min_i + 1) * (max_j - min_j + 1)) as i32
    }
}
