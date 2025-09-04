// 3516. find-closest-person
// https://leetcode.com/problems/find-closest-person

impl Solution {
    pub fn find_closest(x: i32, y: i32, z: i32) -> i32 {
        let dxz = (x - z).abs();
        let dyz = (y - z).abs();
        if dxz < dyz {
            1
        } else if dxz > dyz {
            2
        } else {
            0
        }
    }
}
