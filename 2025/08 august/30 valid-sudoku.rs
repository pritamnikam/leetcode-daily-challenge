// valid-sudoku
// https://leetcode.com/problems/valid-sudoku


impl Solution {
    pub fn is_valid_sudoku(board: Vec<Vec<char>>) -> bool {
        let mut sets = [[0; 9]; 3];
        for row in 0..9 {
            for (col, &ch) in board[row].iter().enumerate().filter(|(_, ch)| **ch != '.') {
                let m = 1 << (ch as u8 - b'1');
                let bi = (row / 3) * 3 + col / 3;
                sets[0][row] ^= m;
                sets[1][col] ^= m;
                sets[2][bi] ^= m;

                if sets[0][row] & m == 0 ||
                    sets[1][col] & m == 0 ||
                    sets[2][bi] & m == 0 {
                        return false;
                    }
            }
        }
        true
    }
}
