// longest-subarray-with-maximum-bitwise-and
// https://leetcode.com/problems/longest-subarray-with-maximum-bitwise-and

impl Solution {
    pub fn longest_subarray(nums: Vec<i32>) -> i32 {
        let (mut max_value, mut ans, mut current_streak) = (0, 0, 0);

        for num in nums {
            if (max_value < num) {
                max_value = num;
                ans = 0;
                current_streak = 0;
            }

            if (max_value == num) {
                current_streak += 1;
            } else {
                current_streak = 0;
            }

            ans = ans.max(current_streak);
        }
        ans
    }
}
