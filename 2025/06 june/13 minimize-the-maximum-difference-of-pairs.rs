// 2616. minimize-the-maximum-difference-of-pairs
// https://leetcode.com/problems/minimize-the-maximum-difference-of-pairs


impl Solution {
    pub fn minimize_max(mut nums: Vec<i32>, p: i32) -> i32 {
        nums.sort();

        let (mut left, mut right) = (0, nums[nums.len() - 1] - nums[0]);

        while left < right {
            let mid = (left + right) / 2;
            if Solution::can_form_pairs(&nums, mid, p) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        left
    }


    fn can_form_pairs(
        nums: &Vec<i32>,
        mid: i32,
        p: i32
    ) -> bool {
        let (mut count, mut i) = (0, 0);

        while i < nums.len() - 1 && count < p {
            if nums[i+1] - nums[i] <= mid {
                count += 1;
                i += 2;
            } else {
                i += 1;
            }
        }

        count >= p
    }
}
