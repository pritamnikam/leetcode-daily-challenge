// number-of-steps-to-reduce-a-number-in-binary-representation-to-one
// https://leetcode.com/problems/number-of-steps-to-reduce-a-number-in-binary-representation-to-one

impl Solution {
    pub fn num_steps(s: String) -> i32 {
        let mut res = s.len() as i32 -1;
        let mut switch = false;
        for c in s[1..].chars().rev() {
            res += ((c == '1') ^ switch) as i32;
            switch |= (c == '1');
        }
        return res + switch as i32;
    }
}
