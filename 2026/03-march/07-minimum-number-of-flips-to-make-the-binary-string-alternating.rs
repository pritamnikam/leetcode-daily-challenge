// minimum-number-of-flips-to-make-the-binary-string-alternating
// https://leetcode.com/problems/minimum-number-of-flips-to-make-the-binary-string-alternating

impl Solution {
    pub fn min_flips(s: String) -> i32 {
        // CHARACTERASTIC FUNCTION
        let i_func = |ch: char, x: i32| -> i32 {
            if (ch as i32 - '0' as i32) == x {
                1
            } else {
                0
            }
        };


        let n = s.len();
        let chars: Vec<char> = s.chars().collect();
        let mut pre = vec![vec![0; 2]; n];

        for i in 0..n {
            if i == 0 {
                pre[i][0] = i_func(chars[i], 1);
                pre[i][1] = i_func(chars[i], 0);
            } else {
                pre[i][0] = pre[i - 1][1] + i_func(chars[i], 1);
                pre[i][1] = pre[i - 1][0] + i_func(chars[i], 0);
            }
        }
        let mut ans = pre[n - 1][0].min(pre[n - 1][1]);
        if n % 2 == 1 {
            // If n is an odd number, it is also necessary to calculate suf
            let mut suf = vec![vec![0; 2]; n];
            
            // Note the boundary case when i = n - 1
            for i in (0..n).rev() {
                if i == n - 1 {
                    suf[i][0] = i_func(chars[i], 1);
                    suf[i][1] = i_func(chars[i], 0);
                } else {
                    suf[i][0] = suf[i + 1][1] + i_func(chars[i], 1);
                    suf[i][1] = suf[i + 1][0] + i_func(chars[i], 0);
                }
            }
            
            for i in 0..n-1 {
                ans = ans.min(pre[i][0] + suf[i + 1][0]);
                ans = ans.min(pre[i][1] + suf[i + 1][1]);
            }
        }
        
        ans


    }
}
