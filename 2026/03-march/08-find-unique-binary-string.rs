// find-unique-binary-string
// https://leetcode.com/problems/find-unique-binary-string

impl Solution {
    pub fn find_different_binary_string(nums: Vec<String>) -> String {
        let mut answer = String::new();

        for (i, s) in nums.iter().enumerate() {
            let ch = s.chars().nth(i).unwrap();
            answer.push(
                if ch == '0' { '1' }
                else { '0' }
            )
        }
        answer
    }
}
