// 2434. using-a-robot-to-print-the-lexicographically-smallest-string
// https://leetcode.com/problems/using-a-robot-to-print-the-lexicographically-smallest-string

impl Solution {
    pub fn robot_with_string(s: String) -> String {
        let mut cnt = [0; 26];
        for c in s.chars() {
            cnt[(c as u8 - b'a') as usize] += 1;
        }
    
        let mut stack = Vec::new();
        let mut res = String::new();
        let mut min_character = b'a';
        for c in s.chars() {
            stack.push(c);
            cnt[(c as u8 - b'a') as usize] -= 1;
            while min_character != b'z' && cnt[(min_character - b'a') as usize] == 0 {
                min_character += 1;
            }
            while !stack.is_empty() && stack.last().unwrap() <= &(min_character as char) {
                res.push(stack.pop().unwrap());
            }
        }
        
        res
    }
}
