// find-smallest-letter-greater-than-target
// https://leetcode.com/problems/find-smallest-letter-greater-than-target

impl Solution {
    pub fn next_greatest_letter(letters: Vec<char>, target: char) -> char {
        // Find the midpoint between target and target + 1
        // This will never be exact, so we're guaranteed to get
        // an Err result.
        let i = letters.binary_search_by(
                    |t| t.cmp(&target)
                         .then(std::cmp::Ordering::Less));
        *letters.get(i.unwrap_err()).unwrap_or(&letters[0])
    }
}
