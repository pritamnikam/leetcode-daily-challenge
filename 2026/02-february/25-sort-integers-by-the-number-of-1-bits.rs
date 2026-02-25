// sort-integers-by-the-number-of-1-bits
// https://leetcode.com/problems/sort-integers-by-the-number-of-1-bits

impl Solution {
    pub fn sort_by_bits(mut arr: Vec<i32>) -> Vec<i32> {
        arr.sort_unstable_by_key(
            |&i| (i.count_ones(), i)
        );
        arr
    }
}
