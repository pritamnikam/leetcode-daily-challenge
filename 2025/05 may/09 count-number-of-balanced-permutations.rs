// 3343. count-number-of-balanced-permutations
// https://leetcode.com/problems/count-number-of-balanced-permutations

use std::cmp::{max, min};

const MOD: i64 = 1_000_000_007;

impl Solution {
    pub fn count_balanced_permutations(num: String) -> i32 {
        let mut tot = 0;
        let n = num.len();
        let mut cnt = vec![0; 10];
        for ch in num.chars() {
            let d = ch.to_digit(10).unwrap();
            cnt[d as usize] += 1;
            tot += d;
        }

        if tot % 2 != 0 {
            return 0;
        }

        let target = tot / 2;
        let max_odd = (n + 1) / 2;
        let mut comb = vec![vec![0; max_odd as usize + 1]; max_odd as usize + 1];
        let mut f = vec![vec![0; max_odd as usize + 1]; (target + 1) as usize];

        for i in 0..=max_odd {
            comb[i][i] = 1;
            comb[i][0] = 1;
            for j in 1..i {
                comb[i][j] = (comb[i - 1][j] + comb[i - 1][j - 1]) % MOD;
            }
        }

        f[0][0] = 1;
        let mut psum = 0;
        let mut tot_sum = 0;
        for i in 0..=9 {
            /* Sum of the number of the first i digits */
            psum += cnt[i];
             /* Sum of the first i numbers */
            tot_sum += i * cnt[i];
            for odd_cnt in (max(0, psum as i32 - (n as i32 - max_odd as i32)) as usize..= min(psum, max_odd)).rev() {
                let even_cnt = psum - odd_cnt as usize;
                for curr in (max(0, tot_sum as i32 - target as i32) as usize ..= min(tot_sum as usize, target as usize) as usize).rev() {
                    let mut res = 0;
                    for j in (max(0, cnt[i] as i32 - even_cnt as i32) as usize ..= min(cnt[i], odd_cnt)).rev() {
                        if i * j <= curr {
                            /* The current digit is filled with i positions at odd positions, and cnt[i] - j positions at even positions */
                            let ways = (comb[odd_cnt][j] * comb[even_cnt][cnt[i] - j]) % MOD;
                            res = (res + ways * f[curr - i * j][odd_cnt - j]) % MOD;
                        }
                    }
                    f[curr][odd_cnt] = res % MOD;
                }
            }
        }

        f[target as usize][max_odd] as i32
    }
}
