// 2683. neighboring-bitwise-xor
// https://leetcode.com/problems/neighboring-bitwise-xor

impl Solution {
    pub fn does_valid_array_exist(derived: Vec<i32>) -> bool {
        let n = derived.len();
        if n == 1 {
            return derived[0] == 0; // only valid if derived[0] is 0
        }

        fn can_form_original(
            derived: &Vec<i32>,
            start: i32
…        }


        can_form_original(&derived, 0)
            || can_form_original(&derived, 1)
    }
}
