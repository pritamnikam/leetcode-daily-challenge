// maximal-rectangle
// https://leetcode.com/problems/maximal-rectangle

impl Solution {
    pub fn maximal_rectangle(matrix: Vec<Vec<char>>) -> i32 {
        if matrix.len() == 0 {
            return 0;
        }

        let mut res = 0;
        let mut histogram: Vec<i32> = vec![ 0; (matrix[0].len() + 2) ];

        for r in matrix.iter() {
            for (i, val) in r.iter().enumerate() {
                if *val == '0' {
                    histogram[i + 1] = 0;
                } else {
                    histogram[i + 1] += 1;
                }
            }
            res = res.max(Self::maxInHistogram(&histogram));
        }
        res
    }

    pub fn maxInHistogram(hist: &Vec<i32>) -> i32 {
        let mut res: i32 = 0;
        let mut stack: Vec<usize> = vec![];
        
        for (i, val) in hist.iter().enumerate() {
            while stack.len() > 0 && hist[*stack.iter().last().unwrap()] > *val {
                let j = stack.pop().unwrap();
                let width = (i - stack[stack.len() - 1] - 1) as i32;
                res = res.max(hist[j] * width);
            }
            stack.push(i);
        }
        
        return res;
    }
}
