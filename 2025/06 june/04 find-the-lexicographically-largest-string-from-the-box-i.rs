// 3403. find-the-lexicographically-largest-string-from-the-box-i
// https://leetcode.com/problems/find-the-lexicographically-largest-string-from-the-box-i/

impl Solution {
    pub fn answer_string(word: String, num_friends: i32) -> String {
        let num_friends = usize::try_from(num_friends).unwrap();

        if num_friends == 1 { return word; }

        let max_substr_len = word.len() - (num_friends - 1);

        let mut max_so_far: Option<&str> = None;

        for b in 0..word.len() {
            let end_idx = *std::cmp::min(&word.len(), &(b + max_substr_len));
            if end_idx > word.len() { continue; }
            let candidate = Some(&word[b..end_idx]);
            max_so_far = *std::cmp::max(&max_so_far, &candidate);
        }

        return max_so_far.unwrap().to_string();
    }
}
