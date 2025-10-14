// 3349. adjacent-increasing-subarrays-detection-i
// https://leetcode.com/problems/adjacent-increasing-subarrays-detection-i

impl Solution {
    pub fn has_increasing_subarrays(nums: Vec<i32>, k: i32) -> bool {
        // Initialize three pointers:
        // lptr: points to start of previous increasing subarray
        // mptr: points to start of current increasing subarray
        // rptr: points to current element being checked
        let mut lptr = -1;
        let mut mptr = 0;
        let mut rptr = 1;

        while rptr < nums.len() as i32 {
            // If current element breaks the increasing sequence
            if nums[rptr as usize] <= nums[rptr as usize - 1] {
                // Check if current increasing subarray is long enough (>= 2k)
                if rptr - mptr >= 2 * k {
                    return true;
                }
                // Check if we have two increasing subarrays of length >= k
                if rptr - mptr >= k && mptr - lptr >= k {
                    return true;
                }
                // Update pointers - previous subarray ends, new one starts
                lptr = mptr;
                mptr = rptr;
            }
            rptr += 1;
        }
        // Final check after loop ends:
        // Either current subarray is >= 2k long
        // OR we have two subarrays >= k long (and lptr is valid)
        rptr - mptr >= 2 * k 
        || (rptr - mptr >= k && mptr - lptr >= k)
    }
}
