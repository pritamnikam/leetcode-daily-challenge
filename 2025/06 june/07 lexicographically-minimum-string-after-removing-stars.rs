// 3170. lexicographically-minimum-string-after-removing-stars
// https://leetcode.com/problems/lexicographically-minimum-string-after-removing-stars

impl Solution {
    pub fn clear_stars(s: String) -> String {
        let mut cnt: Vec<Vec<usize>> = vec![vec![]; 26];
        let mut arr: Vec<char> = s.chars().collect();
        let mut indices = Vec::new();

        for (i, &c) in arr.iter().enumerate() {
            if c != '*' {
                cnt[(c as u8 - b'a') as usize].push(i);
            } else {
                for j in 0..26 {
                    if let Some(idx) = cnt[j].pop() {
                        indices.push(idx);
                        break;
                    }
                }
            }
        }

        for idx in indices {
            arr[idx] = '*';
        }

        arr.into_iter()
            .filter(|&c| c!= '*')
            .collect()
    }
}
