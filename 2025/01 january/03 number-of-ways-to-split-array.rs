// number-of-ways-to-split-array
// https://leetcode.com/problems/number-of-ways-to-split-array

impl Solution {
    pub fn ways_to_split_array(nums: Vec<i32>) -> i32 {
        let (mut l, mut r) = (0, nums.iter().map(|&x| x as i64).sum());
        (0..nums.len() - 1).filter(|&i| {
            l += nums[i] as i64;
            r -= nums[i] as i64;
            l >= r
        }).count() as _
    }
}
