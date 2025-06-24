// 2200. find-all-k-distant-indices-in-an-array
// https://leetcode.com/problems/find-all-k-distant-indices-in-an-array

impl Solution {
    pub fn find_k_distant_indices(nums: Vec<i32>, key: i32, k: i32) -> Vec<i32> {
        let mut res = Vec::new();
        let n = nums.len();
        // traverse number pairs
        for i in 0..n {
            for j in 0..n {
                if nums[j] == key && (i as i32 - j as i32).abs() <= k {
                    res.push(i as i32);
                    break; // early termination to prevent duplicate addition
                }
            }
        }
        res
    }
}
