// 3392. count-subarrays-of-length-three-with-a-condition
// https://leetcode.com/problems/count-subarrays-of-length-three-with-a-condition

impl Solution {
    pub fn count_subarrays(nums: Vec<i32>) -> i32 {
        let (mut i, mut j, n) = (0, 0, nums.len());
        let mut cnt = 0;
        while j < n {
            if j - i + 1 == 3 {
                if nums[i] + nums[j] == nums[i+1]/2 && nums[i+1]%2 == 0 {
                    cnt += 1;
                }
                i += 1;
            }
            j += 1;
        }
        cnt
    }
}
