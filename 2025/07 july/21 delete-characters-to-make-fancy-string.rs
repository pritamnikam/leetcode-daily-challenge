// 1957. delete-characters-to-make-fancy-string
// https://leetcode.com/problems/delete-characters-to-make-fancy-string

impl Solution {
    pub fn make_fancy_string(s: String) -> String {
        let mut chars: Vec<char> = s.chars().collect();
        if chars.len() < 3 {
            return s;
        }

        let mut j = 2;
        for i in 2..chars.len() {
            if chars[i] != chars[j-1] || chars[i] != chars[j-2] {
                chars[j] = chars[i];
                j += 1;
            }
        }

        chars.truncate(j);
        chars.into_iter().collect()
    }
}
