// 3394. check-if-grid-can-be-cut-into-sections
// https://leetcode.com/problems/check-if-grid-can-be-cut-into-sections

impl Solution {
    pub fn check_valid_cuts(n: i32, rectangles: Vec<Vec<i32>>) -> bool {
        let mut xlines = rectangles.iter()
            .map(|e| (e[0], e[2]))
            .collect::<Vec<(i32, i32)>>();

        let mut ylines = rectangles.iter()
            .map(|e| (e[1], e[3]))
            .collect::<Vec<(i32, i32)>>();

        xlines.sort_unstable_by_key(|e| e.0);
        ylines.sort_unstable_by_key(|e| e.0);

        Self::cut_one_dim(&xlines) 
            || Self::cut_one_dim(&ylines)
    }

    fn cut_one_dim(lines: &Vec<(i32, i32)>) -> bool {
        let mut tail = lines[0].1;
        let mut cnt = 0;
        for line in lines.iter() {
            if line.0 >= tail {
                cnt += 1;
                if cnt == 2 {
                    return true;
                }
            }
            tail = tail.max(line.1);
        }
        false
    }
}
