// 3191. minimum-operations-to-make-binary-array-elements-equal-to-one-i
// https://leetcode.com/problems/minimum-operations-to-make-binary-array-elements-equal-to-one-i

impl Solution {
    pub fn min_operations(mut nums: Vec<i32>) -> i32 {
        let (n, mut ans) = (nums.len() - 2, 0);

        for i in 0..n {
            if nums[i] == 1 { continue };
            nums[i + 1] ^= 1;
            nums[i + 2] ^= 1;
            ans += 1;
        }

        if nums[n..] == [1, 1] { ans } else { -1 }
    }
}
