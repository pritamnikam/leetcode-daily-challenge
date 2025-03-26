// 2033. minimum-operations-to-make-a-uni-value-grid
// https://leetcode.com/problems/minimum-operations-to-make-a-uni-value-grid

impl Solution {
    pub fn min_operations(grid: Vec<Vec<i32>>, x: i32) -> i32 {
        // collect and sort all elements
        let mut arr: Vec<i32> = grid.iter()
                                    .flat_map(|row| row.iter())
                                    .cloned()
                                    .collect();
        arr.sort();
        
        // get the median
        let median = arr[arr.len() / 2];
        let mut operations = 0;

        for &num in &arr {
            let diff = (num - median).abs();
            if diff % x != 0 {
                return -1;
            }

            operations += diff / x;
        }
        operations
    }
}
