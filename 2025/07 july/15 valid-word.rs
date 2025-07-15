// 3136. valid-word
// https://leetcode.com/problems/valid-word


impl Solution {
    pub fn is_valid(word: String) -> bool {
        if word.len() < 3 {
            return false;
        }


        let (mut has_vowel, mut has_consonant) = (false, false);

        for ch in word.chars() {
            if ch.is_ascii_alphabetic() {
                let lch = ch.to_ascii_lowercase();
                if "aeiou".contains(lch) {
                    has_vowel = true;
                } else {
                    has_consonant = true;
                }
            } else if !ch.is_ascii_digit() {
                return false;
            }
        }

        has_vowel && has_consonant
    }
}
