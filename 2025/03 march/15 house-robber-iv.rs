// 2560. house-robber-iv
// https://leetcode.com/problems/house-robber-iv

impl Solution {
    pub fn min_capability(nums: Vec<i32>, k: i32) -> i32 {
        // find maximum amount in any house
        let max_money = *nums.iter().max().unwrap();

        // closure to check if at least 'k' houses can be robbed with given 'capability'
        let check_robbable_houses = |capability: i32| {
            nums.iter().fold((0,0), |(prev,curr), &money| {
                if money > capability {
                    // skip house
                    (curr, curr)
                } else {
                    // rob the house
                    (curr, prev + 1)
                }
            }).1 >= k
        };

        // perform binary search on the capability range
        Self::binary_search(0, max_money, check_robbable_houses)
    }

    fn binary_search<F>(mut left: i32, mut right: i32, predicate: F) -> i32
    where
        F: Fn(i32) -> bool,
    {
        while left < right {
            let mid = (left + right) / 2;
            if predicate(mid) {
                // try lower capability
                right = mid;
            } else {
                // increse capability
                left = mid + 1;
            }
        }
        // minimum found capability
        left        
    }
}
