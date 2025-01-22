// 1765. map-of-highest-peak
// https://leetcode.com/problems/map-of-highest-peak/

use std::collections::VecDeque;

impl Solution {
    pub fn highest_peak(is_water: Vec<Vec<i32>>) -> Vec<Vec<i32>> {
        let (m, n) = (is_water.len(), is_water[0].len());
        let mut height = vec![vec![-1; n]; m]; // -1 means unvisited
        let mut queue = VecDeque::new();

        // Directions for BFS: up, down, left, right
        let directions = [(0, 1), (1, 0), (0, -1), (-1, 0)];

        // Initialize the queue with all water cells
        for i in 0..m {
            for j in 0..n {
                if is_water[i][j] == 1 {
                    height[i][j] = 0; // Water cells have height 0
                    queue.push_back((i, j));
                }
            }
        }

        // BFS to assign heights
        while let Some((x, y)) = queue.pop_front() {
            for (dx, dy) in &directions {
                let (nx, ny) = (x as i32 + dx, y as i32 + dy);
                if nx >= 0 && nx < m as i32 && ny >= 0 && ny < n as i32 {
                    let (nx, ny) = (nx as usize, ny as usize);
                    if height[nx][ny] == -1 { // If not visited
                        height[nx][ny] = height[x][y] + 1;
                        queue.push_back((nx, ny));
                    }
                }
            }
        }

        height

    }
}
