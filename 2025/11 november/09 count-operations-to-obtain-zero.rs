// count-operations-to-obtain-zero
// https://leetcode.com/problems/count-operations-to-obtain-zero

impl Solution {
    pub fn count_operations(mut num1: i32, mut num2: i32) -> i32 {
        let mut total_substractions = 0;
        while num1 != 0 && num2 != 0 {
            total_substractions += num1/num2;
            num1 %= num2;
            std::mem::swap(&mut num1, &mut num2);
        }
        total_substractions
    }
}
