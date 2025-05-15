// 2900. longest-unequal-adjacent-groups-subsequence-i
// https://leetcode.com/problems/longest-unequal-adjacent-groups-subsequence-i/

impl Solution {
    pub fn get_longest_subsequence(words: Vec<String>, groups: Vec<i32>) -> Vec<String> {
        let mut ans = Vec::new();
        let n = words.len();

        for i in 0..n {
            if i == 0 || groups[i] != groups[i - 1] {
                ans.push(words[i].clone());
            }
        }
        ans
    }
}
