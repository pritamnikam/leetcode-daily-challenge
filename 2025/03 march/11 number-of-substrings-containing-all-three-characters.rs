// 1358. number-of-substrings-containing-all-three-characters
// https://leetcode.com/problems/number-of-substrings-containing-all-three-characters

impl Solution {
    pub fn number_of_substrings(s: String) -> i32 {
        let mut last_pos = [-1; 3]; // Track last positions of 'a', 'b', 'c'
        let mut total = 0;

        for (pos, ch) in s.chars().enumerate() {
            last_pos[(ch as u8 - b'a') as usize] = pos as i32;

            // Add count of valid substrings ending at current position
            total += 1 + *last_pos.iter().min().unwrap();
        }

        total
    }
}
