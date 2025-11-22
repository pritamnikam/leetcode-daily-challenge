// find-minimum-operations-to-make-all-elements-divisible-by-three
// https://leetcode.com/problems/find-minimum-operations-to-make-all-elements-divisible-by-three

impl Solution {
    pub fn minimum_operations(nums: Vec<i32>) -> i32 {
        nums.iter().map(|&x| { let r = x % 3; r.min(3 - r) }).sum()
    }
}
