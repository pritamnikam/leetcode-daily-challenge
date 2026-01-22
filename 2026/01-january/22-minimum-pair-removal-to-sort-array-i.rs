// minimum-pair-removal-to-sort-array-i
// https://leetcode.com/problems/minimum-pair-removal-to-sort-array-i

impl Solution {
    pub fn minimum_pair_removal(nums: Vec<i32>) -> i32 {
        let mut nums = nums;
        let mut count: i32 = 0;
        while !Self::is_sorted(&nums) {
            count += 1;
            let mut min_sum = i32::MAX;
            let mut position = 0;

            for i in 1..nums.len() {
                let sum = nums[i-1] + nums[i];
                if sum < min_sum {
                    min_sum = sum;
                    position = i;
                }
            }

            nums[position-1] = min_sum;
            nums.remove(position);
        }

        count
    }

    fn is_sorted(nums: &Vec<i32>) -> bool {
        for i in 1..nums.len() {
            if nums[i-1] > nums[i] {
                return false;
            }
        }

        return true;
    }
}
