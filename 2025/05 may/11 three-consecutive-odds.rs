// 1550. three-consecutive-odds
// https://leetcode.com/problems/three-consecutive-odds

impl Solution {
    pub fn three_consecutive_odds(arr: Vec<i32>) -> bool {
        let n = arr.len();

        if (n < 3) {
            return false;
        }

        for i in 0..n-2 {
            let product: i64 = arr[i] as i64 * arr[i + 1] as i64 * arr[i + 2] as i64;
            if (product % 2 == 1) {
                return true;
            }
        }
        false
    }
}
