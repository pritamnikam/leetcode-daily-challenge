// 2145. count-the-hidden-sequences
// https://leetcode.com/problems/count-the-hidden-sequences

impl Solution {
    pub fn number_of_arrays(differences: Vec<i32>, lower: i32, upper: i32) -> i32 {
        let (mut x, mut y, mut cur) = (0,0,0);
        for &d in &differences {
            cur += d;
            x = x.min(cur);
            y = y.max(cur);
            if y - x > upper - lower {
                return 0;
            }
        }
        (upper - lower) - (y - x) + 1
    }
}
