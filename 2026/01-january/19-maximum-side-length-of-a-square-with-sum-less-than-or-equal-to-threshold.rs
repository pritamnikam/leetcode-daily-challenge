// maximum-side-length-of-a-square-with-sum-less-than-or-equal-to-threshold
// https://leetcode.com/problems/maximum-side-length-of-a-square-with-sum-less-than-or-equal-to-threshold

impl Solution {
    pub fn max_side_length(mat: Vec<Vec<i32>>, threshold: i32) -> i32 {
        let m = mat.len();
        let n = mat[0].len();
        let mut P = vec![vec![0; n + 1]; m + 1];
        
        for i in 1..=m {
            for j in 1..=n {
                P[i][j] = P[i-1][j] + P[i][j-1] - P[i-1][j-1] + mat[i-1][j-1] as i32;
            }
        }
        
        let mut l = 1;
        let mut r = m.min(n);
        let mut ans = 0;
        
        while l <= r {
            let mid = (l + r) / 2;
            let mut find = false;
            
            for i in 1..=(m - mid + 1) {
                for j in 1..=(n - mid + 1) {
                    let sum = P[i + mid - 1][j + mid - 1] - P[i - 1][j + mid - 1] - 
                              P[i + mid - 1][j - 1] + P[i - 1][j - 1];
                    if sum <= threshold {
                        find = true;
                        break;
                    }
                }
                if find {
                    break;
                }
            }
            
            if find {
                ans = mid as i32;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        
        ans
    }
}
