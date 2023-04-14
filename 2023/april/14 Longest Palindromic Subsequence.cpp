/*
516. Longest Palindromic Subsequence
https://leetcode.com/problems/longest-palindromic-subsequence/

Given a string s, find the longest palindromic subsequence's length in s.

A subsequence is a sequence that can be derived from another sequence by deleting some or no elements without
changing the order of the remaining elements.

Example 1:
Input: s = "bbbab"
Output: 4
Explanation: One possible longest palindromic subsequence is "bbbb".

Example 2:
Input: s = "cbbd"
Output: 2
Explanation: One possible longest palindromic subsequence is "bb".


Constraints:
1 <= s.length <= 1000
s consists only of lowercase English letters.

*/

using namespace std;

#include <iostream>
#include <vector>
#include <string>

namespace {
    class Solution {
    public:
        int longestPalindromeSubseq(string s) {
            int n = s.length();
            string str1 = s, str2 = s;
            reverse(str2.begin(), str2.end());

            vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

            for (int i = 1; i <= n; ++i) {
                for (int j = 1; j <= n; ++j) {
                    if (str1[i-1] == str2[j-1]) {
                        dp[i][j] = 1 + dp[i - 1][j - 1];
                    }
                    else {
                        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                    }
                }
            }

            return dp[n][n];
        }
    };
} // namespace

void testLongestPalindromicSubsequence() {
    // Example 1:
    // Input: s = "bbbab"
    // Output : 4
    cout << "Longest Palindromic Subsequence: " << Solution().longestPalindromeSubseq("bbbab") << endl;

    // Example 2:
    // Input: s = "cbbd"
    // Output : 2
    cout << "Longest Palindromic Subsequence: " << Solution().longestPalindromeSubseq("cbbd") << endl;
}
