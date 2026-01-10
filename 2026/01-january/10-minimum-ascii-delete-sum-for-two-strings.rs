// minimum-ascii-delete-sum-for-two-strings
// https://leetcode.com/problems/minimum-ascii-delete-sum-for-two-strings


macro_rules! max { ($a: expr, $($b: expr),*) => ($a $(.max($b))*) }

impl Solution {
    pub fn minimum_delete_sum(s1: String, s2: String) -> i32 {
        let (m, n, s1, s2) = (s1.len(), s2.len(), s1.as_bytes(), s2.as_bytes());

        let (mut dp1, mut dp2) = (vec![i32::MIN; n+1], vec![i32::MIN; n+1]);

        for i in 0..m {
            for j in 0..n {
                dp2[j + 1] = max!(dp1[j + 1], dp2[j]);

                if s1[i] == s2[j] {
                    let char_val = s1[i] as i32 * 2;

                    dp2[j + 1] = max!(
                        dp2[j + 1],
                        dp1[j] + char_val,
                        char_val
                    );
                }
            }
            (dp1, dp2) = (dp2, dp1);
        }

        let sum1 = s1.iter().map(|&b| b as i32).sum::<i32>();
        let sum2 = s2.iter().map(|&b| b as i32).sum::<i32>();

        sum1 + sum2 - dp1[n].max(0)
    }
}
