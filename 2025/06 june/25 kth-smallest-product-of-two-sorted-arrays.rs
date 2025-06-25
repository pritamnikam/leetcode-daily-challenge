// 2040. kth-smallest-product-of-two-sorted-arrays
// https://leetcode.com/problems/kth-smallest-product-of-two-sorted-arrays

impl Solution {
    fn f(nums2: &Vec<i32>, x1: i64, v: i64) -> i64 {
        let n2 = nums2.len();
        let (mut left, mut right) = (0, n2 as i32 - 1);
        while left <= right {
            let mid = (left + right) / 2;
            let prod = x1 * nums2[mid as usize] as i64;
            if (x1 >= 0 && prod <= v) || (x1 < 0 && prod > v) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        if x1 >= 0 {
            left as i64
        } else {
            n2 as i64 - left as i64
        }
    }

    pub fn kth_smallest_product(nums1: Vec<i32>, nums2: Vec<i32>, k: i64) -> i64 {
        let (mut left, mut right) = (-1e10 as i64, 1e10 as i64);
        while left <= right {
            let mid = (left + right) / 2;
            let mut count = 0;
            for &x in &nums1 {
                count += Self::f(&nums2, x as i64, mid);
            }
            if count < k {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        left
    }
}
