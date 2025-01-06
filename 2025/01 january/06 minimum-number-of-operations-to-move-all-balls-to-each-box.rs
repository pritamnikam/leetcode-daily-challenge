// 1769. minimum-number-of-operations-to-move-all-balls-to-each-box
// https://leetcode.com/problems/minimum-number-of-operations-to-move-all-balls-to-each-box/

impl Solution {
    pub fn min_operations(boxes: String) -> Vec<i32> {
        let n = boxes.len();
        let boxes: Vec<i32> = boxes.chars().map(|c| c.to_digit(10).unwrap() as i32).collect();
        let mut answer = vec![0; n];

        // left to right
        let mut count = 0;
        let mut operations = 0;
        for i in 0..n {
            answer[i] += operations;
            count += boxes[i];
            operations += count;
        }

        // right to left
        let mut count = 0;
        let mut operations = 0;
        for i in (0..n).rev() {
            answer[i] += operations;
            count += boxes[i];
            operations += count;
        }

        answer
    }
}
