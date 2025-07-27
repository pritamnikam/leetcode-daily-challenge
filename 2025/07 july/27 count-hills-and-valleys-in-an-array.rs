// 2210. count-hills-and-valleys-in-an-array
// https://leetcode.com/problems/count-hills-and-valleys-in-an-array
impl Solution {
    pub fn count_hill_valley(nums: Vec<i32>) -> i32 {
        nums.chunk_by(|&a, &b| a == b)
            .scan([-1; 3], |p, h|{
                p.rotate_left(1);
                p[2] = h[0];
                Some((p[0].is_positive() && (p[1] > p[0] && p[1] > p[2] || p[1] < p[0] && p[1] < p[2])) as i32)
            })
            .sum()
    }
}
