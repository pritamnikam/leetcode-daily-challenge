/*
1312. Minimum Insertion Steps to Make a String Palindrome
https://leetcode.com/problems/minimum-insertion-steps-to-make-a-string-palindrome/

Given a string s. In one step you can insert any character at any index of the string.

Return the minimum number of steps to make s palindrome.

A Palindrome String is one that reads the same backward as well as forward.

Example 1:
Input: s = "zzazz"
Output: 0
Explanation: The string "zzazz" is already palindrome we do not need any insertions.

Example 2:
Input: s = "mbadm"
Output: 2
Explanation: String can be "mbdadbm" or "mdbabdm".

Example 3:
Input: s = "leetcode"
Output: 5
Explanation: Inserting 5 characters the string becomes "leetcodocteel".


Constraints:
1 <= s.length <= 500
s consists of lowercase English letters.

*/

using namespace std;

#include <iostream>
#include <string>
#include <vector>

namespace {
    /*
        In order to minimize the insertions, we need to find the difference of length of the longest palindromic subsequence and string length.

            Minimum Insertion required = len(string) – length(lps)
    */
    class Solution {
    public:
        int minInsertions(string s) {
            int n = s.size();
            int k = longestPalindromeSubsequence(s);
            return n - k;
        }

    private:
        int longestPalindromeSubsequence(string& s) {
            string t = s;
            reverse(s.begin(), s.end());
            return lcs(s, t);
        }

        int lcs(string& s1, string& s2) {
            int n = s1.size();
            int m = s2.size();

            vector<int> prev(m + 1, 0), 
                        cur(m + 1, 0);

            for (int ind1 = 1; ind1 <= n; ind1++) {
                for (int ind2 = 1; ind2 <= m; ind2++) {
                    if (s1[ind1 - 1] == s2[ind2 - 1])
                        cur[ind2] = 1 + prev[ind2 - 1];
                    else
                        cur[ind2] = 0 + max(prev[ind2], cur[ind2 - 1]);
                }
                prev = cur;
            }

            return prev[m];
        }
    };
}  // namespace
