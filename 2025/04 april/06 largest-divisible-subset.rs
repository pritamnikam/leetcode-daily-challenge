// 368. largest-divisible-subset
// https://leetcode.com/problems/largest-divisible-subset

impl Solution {
    pub fn largest_divisible_subset(mut nums: Vec<i32>) -> Vec<i32> {
        if nums.is_empty() {
            return vec![];
        }

         // Step 1: Sort the array
        nums.sort();
        let n = nums.len();
        let mut dp = vec![1; n];       // Each number is a subset of size 1
        let mut prev = vec![-1; n];    // To reconstruct path

        let mut max_idx = 0;           // Index of max subset

        // Step 2: Fill dp and prev
        for i in 1..n {
            for j in 0..i {
                if nums[i] % nums[j] == 0 {
                    if dp[j] + 1 > dp[i] {
                        dp[i] = dp[j] + 1;
                        prev[i] = j as i32;
                    }
                }
            }

            if dp[i] > dp[max_idx] {
                max_idx = i;
            }
        }

        // Step 3: Reconstruct the subset
        let mut result = Vec::new();
        let mut current = max_idx as i32;
        while current >= 0 {
            result.push(nums[current as usize]);
            current = prev[current as usize];
        }

        result.reverse();
        result
    }
}
