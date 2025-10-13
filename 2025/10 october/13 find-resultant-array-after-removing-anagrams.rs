// find-resultant-array-after-removing-anagrams
// https://leetcode.com/problems/find-resultant-array-after-removing-anagrams

impl Solution {
    pub fn remove_anagrams(words: Vec<String>) -> Vec<String> {
        let mut res = vec![words[0].clone()];   // result array
        let n = words.len();
        
        // determine if two words are anagrams
        fn compare(word1: &String, word2: &String) -> bool {
            let mut freq = [0; 26];
            for ch in word1.chars() {
                freq[(ch as u8 - b'a') as usize] += 1;
            }
            for ch in word2.chars() {
                freq[(ch as u8 - b'a') as usize] -= 1;
            }
            freq.iter().all(|&x| x == 0)
        }

        for i in 1..n {
            if !compare(&words[i], &words[i - 1]) {
                res.push(words[i].clone());
            }
        }
        res
    }
}
