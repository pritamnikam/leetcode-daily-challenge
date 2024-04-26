// 2370. Longest Ideal Subsequence
// https://leetcode.com/problems/longest-ideal-subsequence

class Solution {
public:
    int longestIdealString(string s, int k) {
        int  N = size(s);
        vector<int> dp(26, 0);

        int result = 0;
        // Updating dp with the i-th character
        for (int i = 0; i < N; i++) {
            int cur = s[i] - 'a';
            int best = 0;

            for (int prev = 0; prev < 26; prev++) {
                if (abs(prev - cur) <= k) {
                    best = max(best, dp[prev]);
                }
            }
            // Appending s[i] to the previous longest ideal subsequence allowed
            dp[cur] = max(dp[cur], best + 1);
            result = max(result, dp[cur]);
        }
        return result;
    }
};
