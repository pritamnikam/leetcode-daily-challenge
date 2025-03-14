// 2226. maximum-candies-allocated-to-k-children
// https://leetcode.com/problems/maximum-candies-allocated-to-k-children

impl Solution {
    pub fn maximum_candies(candies: Vec<i32>, k: i64) -> i32 {
        // total candies
        let total: i64 = candies.iter().map(|&x| x as i64).sum();
        // avarage candies per child
        let split = (total / k).min(10_000_000) as i32;

        let (mut lo, mut hi) = (0, split);
        while lo < hi {
            let mid = (lo + hi + 1) / 2;
            let piles: i64 = candies.iter().map(|&x| (x / mid) as i64).sum();
            if piles >= k {
                lo = mid;
            } else {
                hi = mid - 1;
            }
        }
        lo as i32
    }
}
