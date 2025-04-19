// count-and-say
// https://leetcode.com/problems/count-and-say

impl Solution {
    pub fn count_and_say(n: i32) -> String {
        use std::fmt::Write;
        let mut result = "1".to_string();
        for _ in 1..n {
            result = result.as_bytes()
                        .chunk_by(|a,b| a == b)
                        .fold(String::new(), |mut s, c| {
                            write!(&mut s, "{}{}", c.len(), c[0] as char).unwrap();
                            s
                        });
        }
        result
    }
}
