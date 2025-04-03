// maximum-value-of-an-ordered-triplet-ii
// https://leetcode.com/problems/maximum-value-of-an-ordered-triplet-ii



impl Solution {
    pub fn maximum_triplet_value(nums: Vec<i32>) -> i64 {
        let mut res = 0;
        let mut imax = 0;
        let mut dmax = 0;
        for &num in nums.iter() {
            res = res.max(dmax * num as i64);
            dmax = dmax.max(imax - num as i64);
            imax = imax.max(num as i64);
        }
        res
    }
}
