// 2918. minimum-equal-sum-of-two-arrays-after-replacing-zeros
// https://leetcode.com/problems/minimum-equal-sum-of-two-arrays-after-replacing-zeros

impl Solution {
    pub fn min_sum(nums1: Vec<i32>, nums2: Vec<i32>) -> i64 {
        let (mut sum1, mut sum2, mut zero1, mut zero2) = (0 as i64, 0 as i64, 0, 0);
        for &x in &nums1 {
            sum1 += x as i64;
            if x == 0 {
                sum1 += 1;
                zero1 += 1;
            }
        }

        for &x in &nums2 {
            sum2 += x as i64;
            if x == 0 {
                sum2 += 1;
                zero2 += 1;
            }
        }

        if (zero1 == 0 && sum2 > sum1) || (zero2 == 0 && sum1 > sum2) {
            return -1;
        }

        sum1.max(sum2)
    }
}
