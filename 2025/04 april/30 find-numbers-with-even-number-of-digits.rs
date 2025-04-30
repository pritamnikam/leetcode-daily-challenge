// 1295. find-numbers-with-even-number-of-digits
// https://leetcode.com/problems/find-numbers-with-even-number-of-digits

impl Solution {
    pub fn find_numbers(nums: Vec<i32>) -> i32 {
        nums.into_iter()
            .filter(
                |&num| {
                    matches!(
                        num,
                        10..100|1_000..10_000|100_000
                    )
                }
            )
            .count() as _
    }
}
