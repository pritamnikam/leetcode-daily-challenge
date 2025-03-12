// 2529. maximum-count-of-positive-integer-and-negative-integer
// https://leetcode.com/problems/maximum-count-of-positive-integer-and-negative-integer

impl Solution {
    pub fn maximum_count(nums: Vec<i32>) -> i32 {
        let negatives = Self::binary_search(&nums, 0) as i32;
        let positives = (nums.len() - Self::binary_search(&nums, 1)) as i32;
        if negatives > positives { negatives } else { positives }
    }


    fn binary_search(nums: &Vec<i32>, target: i32) -> usize {
        let (mut l, mut r, mut result) = (0, nums.len() as isize - 1, nums.len());

        while l <= r {
            let mid = ((l + r) / 2) as usize;
            if nums[mid] < target {
                l = mid as isize + 1;
            } else {
                result = mid;
                r = mid as isize - 1
            }
        }
        result
    }
}
