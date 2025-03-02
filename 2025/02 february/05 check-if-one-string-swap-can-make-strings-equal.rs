// 1790. check-if-one-string-swap-can-make-strings-equal
// https://leetcode.com/problems/check-if-one-string-swap-can-make-strings-equal

impl Solution {
    pub fn are_almost_equal(s1: String, s2: String) -> bool {
        s1.bytes()
            .zip(s2.bytes())
            .filter(|(l, r)| l != r)
            .try_fold(Vec::with_capacity(2), |mut acc, (l, r)| {
                match acc.len() {
                    0 => acc.push([l, r]),
                    1 => acc.push([r, l]),
                    _ => return None,
                }
                Some(acc)
            })
            .is_some_and(|v| match v.len() {
                0 => true,
                2 => v[0] == v[1],
                _ => false,
            })
    }
}
