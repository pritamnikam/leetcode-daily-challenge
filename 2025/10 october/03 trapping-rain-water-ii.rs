// 407. trapping-rain-water-ii
// https://leetcode.com/problems/trapping-rain-water-ii

use std::collections::BinaryHeap;
use std::cmp::Reverse;

impl Solution {
    pub fn trap_rain_water(height_map: Vec<Vec<i32>>) -> i32 {

        let n = height_map.len();
        let m = height_map[0].len();

        let mut level = vec![vec![i32::MAX; m]; n];
        let mut q = BinaryHeap::new();

        for i in 0..n {
            for &j in &[0, m-1] {
                level[i][j] = height_map[i][j];
                q.push((Reverse(level[i][j]), i, j))
            }
        }
        for j in 1..m-1 {
            for &i in &[0, n-1] {
                level[i][j] = height_map[i][j];
                q.push((Reverse(level[i][j]), i, j))
            }
        }


        while let Some((Reverse(x), i, j)) = q.pop() {
            let ip = i + 1;
            let im = i.wrapping_sub(1);

            let jp = j + 1;
            let jm = j. wrapping_sub(1);

            for &(ii, jj) in &[(ip, j), (im, j), (i, jp), (i, jm)] {
                if ii < n && jj < m && level[ii][jj] == i32::MAX {
                    level[ii][jj] = x;
                    q.push(
                        (
                            Reverse(x.max(height_map[ii][jj])),
                            ii, jj
                        )
                    );
                }
            }
        }

        let mut total = 0;
        for i in 0..n {
            for j in 0..m {
                total += (level[i][j] - height_map[i][j]).max(0);
            }
        }
        total
    }
}
