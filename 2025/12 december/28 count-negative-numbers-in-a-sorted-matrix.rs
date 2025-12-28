// count-negative-numbers-in-a-sorted-matrix
// https://leetcode.com/problems/count-negative-numbers-in-a-sorted-matrix/

impl Solution {
    pub fn count_negatives(grid: Vec<Vec<i32>>) -> i32 {
        grid.iter()
            .flat_map(|x| x.iter().filter(|x| x.is_negative()))
            .count() as i32 
    }
}
