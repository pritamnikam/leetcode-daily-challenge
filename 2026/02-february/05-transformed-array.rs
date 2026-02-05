// transformed-array
// https://leetcode.com/problems/transformed-array

impl Solution {
    pub fn construct_transformed_array(nums: Vec<i32>) -> Vec<i32> {
        let n = nums.len();
        nums.iter()
            .enumerate()
            .map(|(i, &num)| nums[((i as i32 + num) % n as i32 + n as i32) as usize % n])
            .collect()
    }
}
