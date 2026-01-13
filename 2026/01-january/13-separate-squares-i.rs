// separate-squares-i
// https://leetcode.com/problems/separate-squares-i

impl Solution {
    pub fn separate_squares(squares: Vec<Vec<i32>>) -> f64 {
        let mut start = 0.0;
        let mut end = 2e9;

        let helper = |mid: f64| -> i32 {
            let (mut upper, mut lower) = (0.0, 0.0);
            for sq in &squares {
                let (x, y, l) = (sq[0] as f64, sq[1] as f64, sq[2] as f64);
                if y > mid {
                    upper += l * l;
                } else if y + l <= mid {
                    lower += l * l;
                } else {
                    lower += (mid - y) * l;
                    upper += (l - (mid - y)) * l;
                }
            }
            if upper == lower { 0 } else if upper > lower { 1 } else { -1 }
        };

        while (end - start) > 1e-5 {
            let mid = (start + end) / 2.0;
            if helper(mid) == 1 {
                start = mid;
            } else {
                end = mid;
            }
        }
        (end * 1e5).round() / 1e5
    }
}
