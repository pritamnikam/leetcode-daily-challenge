// 909. snakes-and-ladders
// https://leetcode.com/problems/snakes-and-ladders

use std::collections::VecDeque;

impl Solution {
    pub fn snakes_and_ladders(board: Vec<Vec<i32>>) -> i32 {
        let n = board.len();
        let mut flatboard = Vec::<i32>::new();

        let mut toggle = true;
        for row in board.iter().rev() {
            if toggle {
                flatboard.extend(row.iter());
            } else {
                flatboard.extend(row.iter().rev());
            }
            toggle = !toggle;
        }

        let (mut q, mut best) = (VecDeque::new(), vec![-1; (n * n) as usize]);
        q.push_back(0);
        best[0] = 0;

        while let Some(index) = q.pop_front() {
            for i in index + 1 .. (index + 7).min((n * n)) {
                let mut new_index = i;

                if flatboard[new_index] != -1 {
                    new_index = (flatboard[new_index] - 1) as usize;
                }

                if new_index == (n * n) - 1 {
                    return best[index] + 1;
                }

                if best[new_index] == -1 {
                    q.push_back(new_index);
                    best[new_index] = best[index] + 1;
                }
            }
        }

        -1
    }
}
