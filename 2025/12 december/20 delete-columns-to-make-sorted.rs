// delete-columns-to-make-sorted
// https://leetcode.com/problems/delete-columns-to-make-sorted
impl Solution {
    pub fn min_deletion_size(strs: Vec<String>) -> i32 {
        (0..strs[0].len()).fold(0, |acc, x| {
            acc + strs.windows(2).any(
                |w| w[1].as_bytes()[x] < w[0].as_bytes()[x]
            ) as i32
        })
    }
}
