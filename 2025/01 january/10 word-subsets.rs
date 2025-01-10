// 916. word-subsets
// https://leetcode.com/problems/word-subsets/

use std::collections::HashMap;

impl Solution {
    pub fn word_subsets(words1: Vec<String>, words2: Vec<String>) -> Vec<String> {
        fn count_chars_freq(word: &str) -> HashMap<char, usize> {
            let mut freq = HashMap::new();
            for c in word.chars() {
                *freq.entry(c).or_insert(0) += 1;
            }
            freq
        }

        fn is_universal(word: &str, max_freq: &HashMap<char, usize>) -> bool {
            let word_freq = count_chars_freq(word);
            for (&ch, &count) in max_freq {
                if word_freq.get(&ch).unwrap_or(&0) < &count {
                    return false;
                }
            }
            true
        }

        let mut max_freq = HashMap::new();
        for word in words2 {
            let freq = count_chars_freq(&word);
            for (ch, count) in freq {
                let entry = max_freq.entry(ch).or_insert(0);
                *entry = (*entry).max(count);
            }
        }

        words1
            .into_iter()
            .filter(|word| is_universal(word, &max_freq))
            .collect()
    }
}
