// 2176. count-equal-and-divisible-pairs-in-an-array
// https://leetcode.com/problems/count-equal-and-divisible-pairs-in-an-array

impl Solution {
    pub fn count_pairs(nums: Vec<i32>, k: i32) -> i32 {
        let n = nums.len();
        let mut res = 0;

        for i in 0..n-1 {
            for j in i + 1..n {
                if (i * j) % k as usize == 0 && nums[i] == nums[j] {
                    res += 1
                }
            }
        }
        res
    }
}
