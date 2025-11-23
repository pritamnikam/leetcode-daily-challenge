// greatest-sum-divisible-by-three
// https://leetcode.com/problems/greatest-sum-divisible-by-three


impl Solution {
    pub fn max_sum_div_three(nums: Vec<i32>) -> i32 {
        nums.into_iter()
            .fold(
                (0, i32::MIN, i32::MIN), |(z, o, t), v| 
                match v % 3 {
                    1 => (z.max(t + v), o.max(z + v), t.max(o + v)),
                    2 => (z.max(o + v), o.max(t + v), t.max(z + v)),
                    _ => (z + v, o + v, t + v),
                }
            )
            .0
    }
}
