// maximum-value-of-an-ordered-triplet-i
// https://leetcode.com/problems/maximum-value-of-an-ordered-triplet-i

impl Solution {
    pub fn maximum_triplet_value(nums: Vec<i32>) -> i64 {
        let mut max_sum: i64 = 0;
        let n = nums.len();

        for i in 0..n {
            for j in i+1..n {
                for k in j+1..n {
                    let value = (nums[i] as i64 - nums[j] as i64) * nums[k] as i64;
                    max_sum = max_sum.max(value);
                }
            }
        }
        max_sum
    }
}
