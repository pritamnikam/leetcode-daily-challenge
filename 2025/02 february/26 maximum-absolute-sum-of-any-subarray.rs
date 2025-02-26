// 1749. maximum-absolute-sum-of-any-subarray
// https://leetcode.com/problems/maximum-absolute-sum-of-any-subarray/

impl Solution {
    pub fn max_absolute_sum(nums: Vec<i32>) -> i32 {
        let mut minPrefixSum = 0;
        let mut maxPrefixSum = 0;

        let mut prefixSum = 0;
        for (i, num) in nums.iter().enumerate() {
            prefixSum += num;
            minPrefixSum = minPrefixSum.min(prefixSum);
            maxPrefixSum = maxPrefixSum.max(prefixSum);
        }

        maxPrefixSum - minPrefixSum
    }
}
