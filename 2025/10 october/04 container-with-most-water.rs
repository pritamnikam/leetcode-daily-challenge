// 11. container-with-most-water
// https://leetcode.com/problems/container-with-most-water

impl Solution {
    pub fn max_area(height: Vec<i32>) -> i32 {
        if (height.is_empty()) {
            return 0;
        }

        let (mut left, mut right) = (0usize, height.len() - 1);
        let mut max_area: i64 = 0;

        while left < right {
            let area = 
                (std::cmp::min(height[left], height[right]) as i64)
                * ((right - left) as i64);
            max_area = max_area.max(area);

            if height[left] < height[right] {
                left += 1;
            } else {
                right -= 1;
            }
        }
        max_area as i32
    }
}
