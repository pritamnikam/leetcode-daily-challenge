// 3227. vowels-game-in-a-string
// https://leetcode.com/problems/vowels-game-in-a-string

impl Solution {
    pub fn does_alice_win(s: String) -> bool {
        s.chars()
            .any(
                |ch| matches!(
                    ch, 'a' | 'e' | 'i' | 'o' | 'u'
                )
            )
    }
}
