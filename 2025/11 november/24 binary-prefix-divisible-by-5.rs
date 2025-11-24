// binary-prefix-divisible-by-5
// https://leetcode.com/problems/binary-prefix-divisible-by-5

impl Solution {
    pub fn prefixes_div_by5(nums: Vec<i32>) -> Vec<bool> {
        let n = nums.len();
        let mut sum = 0;
        let mut ans = Vec::new();

        for num in nums {
            sum += num;
            sum %= 5;
            if sum == 0 {
                ans.push(true);
            } else {
                ans.push(false);
            }
            sum <<= 1;
        }

        ans
    }
}
