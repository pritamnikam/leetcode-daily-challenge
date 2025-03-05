// 2579. count-total-number-of-colored-cells
// https://leetcode.com/problems/count-total-number-of-colored-cells

impl Solution {
    pub fn colored_cells(n: i32) -> i64 {
        let n: i64 = n as i64;
        n * (n - 1) * 2 + 1
    }
}
