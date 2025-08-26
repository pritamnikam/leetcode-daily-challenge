// maximum-area-of-longest-diagonal-rectangle
// https://leetcode.com/problems/maximum-area-of-longest-diagonal-rectangle

impl Solution {
    pub fn area_of_max_diagonal(dimensions: Vec<Vec<i32>>) -> i32 {
        let mut max_dia_sq = 0;
        let mut max_area = 0;

        for dim in dimensions {
            let l = dim[0];
            let w = dim[1];

            let dia_sq = l * l + w * w;
            let area = l * w;
            if dia_sq > max_dia_sq {
                max_dia_sq = dia_sq;
                max_area = area;
            } else {
                max_area = max_area.max(area);
            }
        }
        max_area
    }
}
