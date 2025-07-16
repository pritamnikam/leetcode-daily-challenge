// 3201. find-the-maximum-length-of-valid-subsequence-i
// https://leetcode.com/problems/find-the-maximum-length-of-valid-subsequence-i

impl Solution {
    pub fn maximum_length(nums: Vec<i32>) -> i32 {
        let mut res = 0;
        let patterns = vec![vec![0, 0], vec![0, 1], vec![1, 0], vec![1, 1]];

        for pattern in patterns {
            let mut count = 0;

            for num in &nums {
                if num % 2 == pattern[count % 2] {
                    count += 1;
                }
            }

            res = res.max(count);
        }

        res as i32
    }
}
