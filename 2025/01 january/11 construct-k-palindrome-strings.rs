// 1400. construct-k-palindrome-strings
// https://leetcode.com/problems/construct-k-palindrome-strings/

use std::collections::HashMap;

impl Solution {
    // pub fn can_construct(s: String, k: i32) -> bool {
    //   s.len() >= k as usize 
    //     && s.bytes()
    //         .fold(0u32, |acc, b| acc ^ |1 << b - b'a')
    //         .count_ones() <= k as u32
    // }
  
    pub fn can_construct(s: String, k: i32) -> bool {
        if k as usize > s.len() {
            return false;
        }

        let mut freq = HashMap::new();
        for c in s.chars() {
            *freq.entry(c).or_insert(0) += 1;
        }

        let odd_count = freq
                            .values()
                            .filter(|&&count| count % 2 != 0)
                            .count();
        odd_count <= k as usize
    }
}
