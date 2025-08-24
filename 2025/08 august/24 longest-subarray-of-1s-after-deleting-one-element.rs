// longest-subarray-of-1s-after-deleting-one-element
// https://leetcode.com/problems/longest-subarray-of-1s-after-deleting-one-element

impl Solution {
    pub fn longest_subarray(nums: Vec<i32>) -> i32 {
        let (mut zero_count, mut longest_window, mut start) = (0, 0, 0);
        
        for i in 0..nums.len() {
            zero_count += if(nums[i] == 0)  { 1 } else { 0 };

            // Shrink the window until the count of zero's
            // is less than or equal to 1.
            while (zero_count > 1) {
                zero_count -= if(nums[start] == 0)  { 1 } else { 0 };
                start += 1;
            }

            longest_window = longest_window.max(i- start);
        }
        longest_window as i32
    }
}
