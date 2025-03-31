// 2551. put-marbles-in-bags
// https://leetcode.com/problems/put-marbles-in-bags

impl Solution {
    pub fn put_marbles(weights: Vec<i32>, k: i32) -> i64 {
        if k == 1 {
            return 0;
        }

        // pair the weightd
        let mut pair_sums: Vec<i32> = weights.windows(2).map(|w| w[0] + w[1]).collect();

        // sort paier O(n x log(n))
        pair_sums.sort();

        let min_score: i64 = pair_sums.iter().take((k-1) as usize).map(|&x| x as i64).sum();
        let max_score: i64 = pair_sums.iter().rev().take((k-1) as usize).map(|&x| x as i64).sum();

        max_score - min_score
    }
}
