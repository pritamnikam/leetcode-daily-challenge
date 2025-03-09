// 3208. alternating-groups-ii
// https://leetcode.com/problems/alternating-groups-ii

impl Solution {
    pub fn number_of_alternating_groups(colors: Vec<i32>, k: i32) -> i32 {
        colors[1..]
            .iter()
            .chain(&colors[0..k as usize - 1])
            .copied()
            .fold((colors[0], 1, 0), |(prev, count, ans), color| {
                if color != prev {
                    (color, count + 1, ans + (count + 1 >= k) as i32)
                } else {
                    (color, 1, ans)
                }
            })
            .2
    }
}
