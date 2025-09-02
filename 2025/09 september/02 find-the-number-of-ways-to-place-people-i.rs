// 3025. find-the-number-of-ways-to-place-people-i
// https://leetcode.com/problems/find-the-number-of-ways-to-place-people-i/

impl Solution {
    pub fn number_of_pairs(points: Vec<Vec<i32>>) -> i32 {
        let mut ans = 0;
        let n = points.len();

        for i in 0..n {
            let pointA = &points[i];
            for j in 0..n {
                let pointB = &points[j];
                if i == j || !(pointA[0] <= pointB[0] && pointA[1] >= pointB[1]) {
                    continue;
                }
                if n == 2 {
                    ans += 1;
                    continue;
                }

                let mut illegal = false;
                for k in 0..n {
                    if k == i || k == j {
                        continue;
                    }

                    let pointTmp = &points[k];
                    let isXContained = pointTmp[0] >= pointA[0] && pointTmp[0] <= pointB[0];
                    let isYContained = pointTmp[1] <= pointA[1] && pointTmp[1] >= pointB[1];
                    if isXContained && isYContained {
                        illegal = true;
                        break;
                    }
                }
                if !illegal {
                    ans += 1;
                }
            }
        }
        ans
    }
}
