// 37. sudoku-solver
// https://leetcode.com/problems/sudoku-solver

impl Solution {
    fn mark(grid: &mut[[u16;9];3], i: usize, j: usize, val: u8) -> bool {
        let val = 1 << val;
        if  grid[0][i] & val != 0 || 
            grid[1][j] & val != 0 || 
            grid[2][i / 3 * 3 + j / 3] & val != 0 {
            return false;
        }
        grid[0][i] |= val; 
        grid[1][j] |= val;
        grid[2][i / 3 * 3 + j / 3] |= val;
        return true; 
    }
    fn unmark(grid: &mut[[u16;9];3], i: usize, j: usize, val: u8) {
        let val = 1 << val;
        grid[0][i] ^= val; 
        grid[1][j] ^= val;
        grid[2][i / 3 * 3 + j / 3] ^= val;
    }
    
    pub fn solve_sudoku(board: &mut Vec<Vec<char>>) {
        let len = 9;
        let mut grid: [[u16;9];3] = [[0;9];3];
        let mut squares = vec![];
        for i in 0..len {
            for j in 0..len {
                if board[i][j] != '.' {
                    Self::mark(&mut grid, i, j, board[i][j] as u8 - b'0'); 
                } else {
                    squares.push(((i,j),0));
                }
            }
        }
        let mut curr_square = 0;
        while curr_square < squares.len() {
            let (i, j) = squares[curr_square].0;
            let mut curr_val = squares[curr_square].1;
            if curr_val > 0 {
                Self::unmark(&mut grid, i, j, curr_val);
            }
            curr_val += 1;
            while curr_val <= 9 {
                if Self::mark(&mut grid, i ,j, curr_val) {
                    board[i][j] = (curr_val + b'0') as char;
                    squares[curr_square].1 = curr_val;
                    curr_square += 1;
                    break;
                }
                curr_val += 1;
            }
            if curr_val > 9 {
                board[i][j] = '.';
                squares[curr_square].1 = 0;
                curr_square -= 1;
            }
        }
    }
}
