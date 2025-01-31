// 1267. count-servers-that-communicate
// https://leetcode.com/problems/count-servers-that-communicate

impl Solution {
    pub fn count_servers(grid: Vec<Vec<i32>>) -> i32 {
        let mut rows = vec![0; grid.len()];
        let mut cols = vec![0; grid[0].len()];
        for y in 0..grid.len() {
            for x in 0..grid[0].len() {
                if grid[y][x] == 1 {
                    rows[y] += 1;
                    cols[x] += 1;
                }
            }
        }
        (0..grid.len())
            .flat_map(|y| (0..grid[0].len()).map(move |x| [y, x]))
            .fold(0, |acc, [y, x]| {
                acc + (grid[y][x] == 1 && rows[y].max(cols[x]) > 1) as i32
            })
    }
}
