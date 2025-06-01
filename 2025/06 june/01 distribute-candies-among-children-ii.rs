// 2929. distribute-candies-among-children-ii
// https://leetcode.com/problems/distribute-candies-among-children-ii

impl Solution {
    pub fn distribute_candies(n: i32, limit: i32) -> i64 {
        let mut ans: i64 = 0;
        for i in 0..=std::cmp::min(limit, n) {
            if n - i > 2 * limit {
                continue;
            }

            ans += std::cmp::min(n - i, limit) as i64
                    - std::cmp::max(0, n - i - limit) as i64
                    + 1
        }
        ans
    }
}
