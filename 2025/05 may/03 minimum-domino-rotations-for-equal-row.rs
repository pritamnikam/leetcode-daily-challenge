// 1007. minimum-domino-rotations-for-equal-row
// https://leetcode.com/problems/minimum-domino-rotations-for-equal-row

impl Solution {
    pub fn min_domino_rotations(tops: Vec<i32>, bottoms: Vec<i32>) -> i32 {
        fn solve(tops: &Vec<i32>, bottoms: &Vec<i32>, to_check: i32) -> i32 {
            let mut result = 0;
            let mut solved = true;
            for idx in 0..tops.len() {
                if tops[idx] == to_check { continue; }
                if bottoms[idx] == to_check { result += 1; continue;}
                solved = false;
                break;
            }            
            if !solved { i32::MAX } else { result }
        }
        let result = solve(&tops,&bottoms,tops[0])
            .min(solve(&bottoms,&tops,tops[0])
            .min(solve(&tops,&bottoms,bottoms[0])
            .min(solve(&bottoms,&tops,bottoms[0]))));            
        if result != i32::MAX { result } else { -1 }
    }
}
