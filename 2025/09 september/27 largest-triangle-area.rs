// largest-triangle-area
// https://leetcode.com/problems/largest-triangle-area

impl Solution {
    pub fn largest_triangle_area(points: Vec<Vec<i32>>) -> f64 {
        let n = points.len();
        let mut max_area = 0 as f64;

        for i in (0..n-2) {
            let (a0, a1) = (points[i][0], points[i][1]);
            for j in (i+1..n-1) {
                for k in (j+1..n) {
                    let mut area: f64 = 0.5 as f64 * ((points[j][0]-a0)*(points[k][1]-a1)-(points[j][1]-a1)*(points[k][0]-a0)) as f64;
                    if (area < 0 as f64) {
                        area *= (-1 as f64);
                    }
                    max_area = max_area.max(area);
                }
            }
        }
        max_area
    }
}
