// max-dot-product-of-two-subsequences
// https://leetcode.com/problems/max-dot-product-of-two-subsequences

// Intuition
// This is a DP problem, for which, a common algorithm can be used with some minor modifications.

// def reusable_2d_dp_skeleton(self, list1, list2):
//     curr = [INIT_VAL] * (max(len(list1), len(list2)) + 1)
//     prev = curr[:] # Shallow copy.

//     for i in range(1, len(list1) + 1):
//         for j in range(1, len(list2) + 1):
//             # Perform specific operations here, then get the
//             # maximum (or min if the problems constraints ask for it)
//             # value from adjacent indices in curr and prev and update
//             # the current result index.
//             curr[j] = max(...)

//         curr, prev = prev, curr # Swap.

//     return prev[...] # Return value at appropriate final index.
// 
// This basic skeleton can be used often with DP problems that require a 2D array to memoize prior step results. In lieu of a 2D array, 
// this approach only needs two 1D arrays, which get swapped each time the inner loop completes. This can lower the runtime memory needed.


macro_rules! max {
    ( $term1:expr, $( $term2:expr ),* ) => {{
        $term1 $( .max($term2) )*
    }}
}

impl Solution {
    pub fn max_dot_product(nums1: Vec<i32>, nums2: Vec<i32>) -> i32 {
        use std::mem::swap;
        let len1 = nums1.len();
        let len2 = nums2.len();

        let mut curr = vec![i32::MIN; len2 + 1];
        let mut prev = vec![i32::MIN; len2 + 1];
        let mut prod;

        for i in 1..=len1 {
            for j in 1..=len2 {
                prod = nums1[i - 1] * nums2[j - 1];

                curr[j] = max!(prod, 
                               prod + max!(0, prev[j - 1]),
                               curr[j - 1], 
                               prev[j]);
            }
            swap(&mut curr, &mut prev);
        }
        prev[len2]
    }
}
