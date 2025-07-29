// 2411. smallest-subarrays-with-maximum-bitwise-or
// https://leetcode.com/problems/smallest-subarrays-with-maximum-bitwise-or

impl Solution {
    pub fn smallest_subarrays(nums: Vec<i32>) -> Vec<i32> {
        let n = nums.len();
        let mut pos = vec![-1; 31];
        let mut ans = vec![0; n];
        for i in (0..n).rev() {
            let mut j = i;
            for bit in 0..31 {
                if (nums[i] & (1 << bit)) == 0 {
                    if pos[bit] != -1 {
                        j = j.max(pos[bit] as usize);
                    }
                } else {
                    pos[bit] = i as i32;
                }
            }
            ans[i] = (j - i + 1) as i32;
        }
        ans
    }
}
