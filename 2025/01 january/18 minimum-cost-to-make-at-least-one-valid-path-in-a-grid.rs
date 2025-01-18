// 1368. minimum-cost-to-make-at-least-one-valid-path-in-a-grid
// https://leetcode.com/problems/minimum-cost-to-make-at-least-one-valid-path-in-a-grid/

use std::collections::BinaryHeap;
use std::cmp::Reverse; 

impl Solution {
    pub fn min_cost(grid: Vec<Vec<i32>>) -> i32 {
        let directions = [(0, 1), (0, -1), (1, 0), (-1, 0)];
        let m = grid.len();
        let n = grid[0].len();

        let mut dist = vec![vec![i32::MAX; n]; m]; // Store minimum cost to reach each cell
        let mut heap = BinaryHeap::new(); // Min-Heap (Dijkstra's Algorithm)
        
        // Push starting cell (cost = 0)
        heap.push((Reverse(0), 0, 0)); // (cost, row, col)
        dist[0][0] = 0;

        while let Some((Reverse(cost), r, c)) = heap.pop() {
            if r == m - 1 && c == n - 1 {
                return cost; // Reached bottom-right cell
            }

            for (dir, (dr, dc)) in directions.iter().enumerate() {
                let new_r = (r as i32 + dr) as usize;
                let new_c = (c as i32 + dc) as usize;

                if new_r < m && new_c < n {
                    let expected_dir = grid[r][c] - 1; // Convert (1,2,3,4) to (0,1,2,3)
                    let new_cost = if dir as i32 == expected_dir { cost } else { cost + 1 };

                    if new_cost < dist[new_r][new_c] {
                        dist[new_r][new_c] = new_cost;
                        heap.push((Reverse(new_cost), new_r, new_c));
                    }
                }
            }
        }

        -1 // Should never reach here

    }
}
