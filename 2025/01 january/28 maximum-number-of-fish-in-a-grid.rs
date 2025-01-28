// maximum-number-of-fish-in-a-grid
// https://leetcode.com/problems/maximum-number-of-fish-in-a-grid/

impl Solution {
    pub fn find_max_fish(grid: Vec<Vec<i32>>) -> i32 {
        let mut grid = grid; // Mutable copy of grid
        let rows = grid.len();
        let cols = grid[0].len();
        let mut max_fish = 0;

        // Helper function for DFS
        fn dfs(grid: &mut Vec<Vec<i32>>, r: usize, c: usize) -> i32 {
            if r >= grid.len() || c >= grid[0].len() || grid[r][c] == 0 {
                return 0; // Base case: Stop if out of bounds or on land
            }
            
            let fish = grid[r][c]; // Collect fish
            grid[r][c] = 0; // Mark as visited
            
            let mut total_fish = fish;
            let directions = [(0, 1), (1, 0), (0, -1), (-1, 0)];

            for &(dr, dc) in &directions {
                let nr = r as isize + dr;
                let nc = c as isize + dc;
                if nr >= 0 && nr < grid.len() as isize && nc >= 0 && nc < grid[0].len() as isize {
                    total_fish += dfs(grid, nr as usize, nc as usize);
                }
            }

            total_fish
        }

        // Iterate through grid and start DFS from each unvisited water cell
        for r in 0..rows {
            for c in 0..cols {
                if grid[r][c] > 0 {
                    max_fish = max_fish.max(dfs(&mut grid, r, c));
                }
            }
        }

        max_fish
    }
}
