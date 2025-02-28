// 1092. Shortest Common Subsequence
//
impl Solution {
  pub fn shortest_common_supersequence(str1: String, str2: String) -> String {
    let m = str1.len();
    let n = str2.len();
    let str1 = str1.as_bytes();
    let str2 = str2.as_bytes();

    // Step 1: Compute LCS using DP
    let mut dp = vec![vec![0; n + 1]; m + 1];

    for i in 1..=m {
        for j in 1..=n {
            if str1[i - 1] == str2[j - 1] {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = dp[i - 1][j].max(dp[i][j - 1]);
            }
        }
    }

    // Step 2: Build the shortest common supersequence
    let mut result = String::new();
    let (mut i, mut j) = (m, n);

    while i > 0 || j > 0 {
        if i > 0 && j > 0 && str1[i - 1] == str2[j - 1] {
            result.push(str1[i - 1] as char);
            i -= 1;
            j -= 1;
        } else if j > 0 && (i == 0 || dp[i][j - 1] >= dp[i - 1][j]) {
            result.push(str2[j - 1] as char);
            j -= 1;
        } else {
            result.push(str1[i - 1] as char);
            i -= 1;
        }
    }

    result.chars().rev().collect()
}
}
