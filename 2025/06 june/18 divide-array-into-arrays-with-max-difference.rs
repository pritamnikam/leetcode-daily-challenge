// 2966. divide-array-into-arrays-with-max-difference
// https://leetcode.com/problems/divide-array-into-arrays-with-max-difference

impl Solution {
    pub fn divide_array(nums: Vec<i32>, k: i32) -> Vec<Vec<i32>> {
        let mut nums = nums;

        nums.sort();
        let mut res = vec![];
        for i in (2..nums.len()).step_by(3) {
            if nums[i] - nums[i-2] > k {
                return vec![];
            }

            res.push(
                vec![ nums[i-2], nums[i-1], nums[i] ]
            );
        }
        res
    }
}
