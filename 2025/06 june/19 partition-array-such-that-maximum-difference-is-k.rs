// 2294. partition-array-such-that-maximum-difference-is-k
// https://leetcode.com/problems/partition-array-such-that-maximum-difference-is-k

impl Solution {
    pub fn partition_array(mut nums: Vec<i32>, k: i32) -> i32 {
        nums.sort();

        let mut ans = 1;
        let mut rec = nums[0];

        for &num in &nums {
            if num - rec > k {
                ans += 1;
                rec = num;
            }
        }

        ans
    }
}
