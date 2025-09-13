// 3541. find-most-frequent-vowel-and-consonant
// https://leetcode.com/problems/find-most-frequent-vowel-and-consonant

impl Solution {

    fn is_vowel(ch: usize) -> bool {
        matches!(
            ch as u8 + b'a', 
                   b'a' 
                 | b'e' 
                 | b'i'
                 | b'o'
                 | b'u'
        )
    }

    pub fn max_freq_sum(s: String) -> i32 {
        let mut freq = [0; 26];
        for ch in s.chars() {
            freq[(ch as u8 - b'a') as usize] += 1;
        }

        let (mut vowel, mut consonant) = (0, 0);
        for (i, &f) in freq.iter().enumerate() {
            if Self::is_vowel(i) {
                vowel = vowel.max(f);
            } else {
                consonant = consonant.max(f);
            }
        }

        vowel + consonant
    }
}
