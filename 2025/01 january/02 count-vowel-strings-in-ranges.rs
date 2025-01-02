// 2559. count-vowel-strings-in-ranges
// https://leetcode.com/problems/count-vowel-strings-in-ranges/

impl Solution {
    pub fn vowel_strings(words: Vec<String>, queries: Vec<Vec<i32>>) -> Vec<i32> {
        fn is_vowel(c: char) -> bool {
            matches!(c, 'a' | 'e' | 'i' | 'o' | 'u')
        }
        //Step 1: precompute which word starts and ends with a vowel
        let mut is_vowel_word = vec![0; words.len()];
        for (i, word) in words.iter().enumerate() {
            if let (Some(first), Some(last)) = (word.chars().next(), word.chars().last()) {
                if is_vowel(first) && is_vowel(last) {
                    is_vowel_word[i] = 1;
                }
            }
        }

        // Step 2: create prefix sum array
        let mut prefix_sum = vec![0; words.len() + 1];
        for i in 0..words.len() {
            prefix_sum[i + 1] = prefix_sum[i] + is_vowel_word[i]; 
        }

        // Step 3: answer each query using the prefix sum array
        let mut results = Vec::with_capacity(queries.len());
        for query in queries {
            let (li, ri) = (query[0], query[1]);
            let count = prefix_sum[ri as usize + 1] - prefix_sum[li as usize];
            results.push(count);
        }

        results
    }
}
