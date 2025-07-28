// 2044. count-number-of-maximum-bitwise-or-subsets
// https://leetcode.com/problems/count-number-of-maximum-bitwise-or-subsets

impl Solution {
    pub fn count_max_or_subsets(nums: Vec<i32>) -> i32 {
        (0..1 << nums.len())
            .fold((0, 0), |(count, max_bo), combo| {
                nums
                    .iter()
                    .enumerate()
                    .filter_map(|(i, num)| ((combo >> i) & 1 == 1).then_some(*num))
                    .reduce(|acc, num| acc | num)
                    .map_or((count, max_bo), |bo| match bo.cmp(&max_bo) {
                        std::cmp::Ordering::Less => (count, max_bo),
                        std::cmp::Ordering::Equal => (count + 1, max_bo),
                        std::cmp::Ordering::Greater => (1, bo),
                    })
            })
            .0
    }
}
