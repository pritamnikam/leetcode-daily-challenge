/*
97. Interleaving String
https://leetcode.com/problems/interleaving-string/

Given strings s1, s2, and s3, find whether s3 is formed by an interleaving of s1 and s2.

An interleaving of two strings s and t is a configuration where s and t are divided into n and m
substrings
 respectively, such that:

s = s1 + s2 + ... + sn
t = t1 + t2 + ... + tm
|n - m| <= 1
The interleaving is s1 + t1 + s2 + t2 + s3 + t3 + ... or t1 + s1 + t2 + s2 + t3 + s3 + ...
Note: a + b is the concatenation of strings a and b.

Example 1:
Input: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac"
Output: true
Explanation: One way to obtain s3 is:
Split s1 into s1 = "aa" + "bc" + "c", and s2 into s2 = "dbbc" + "a".
Interleaving the two splits, we get "aa" + "dbbc" + "bc" + "a" + "c" = "aadbbcbcac".
Since s3 can be obtained by interleaving s1 and s2, we return true.
Example 2:

Input: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbbaccc"
Output: false
Explanation: Notice how it is impossible to interleave s2 with any other string to obtain s3.
Example 3:

Input: s1 = "", s2 = "", s3 = ""
Output: true


Constraints:

0 <= s1.length, s2.length <= 100
0 <= s3.length <= 200
s1, s2, and s3 consist of lowercase English letters.


Follow up: Could you solve it using only O(s2.length) additional memory space?
*/

using namespace std;
#include <iostream>
#include <unordered_map>
#include <string>
namespace {
    class Solution {
    public:
        bool isInterleave(string s1, string s2, string s3) {
            unordered_map<string, bool> dp;
            return isInterleave(dp, s1, s2, s3, 0, 0, 0);
        }

    private:
        bool isInterleave(unordered_map<string, bool>& dp,
            string s1, string s2, string s3, int i, int j, int k) {
            // if we have reached the end of the all the strings
            if (i == s1.length() &&
                j == s2.length() &&
                k == s3.length()) {
                return true;
            }

            // if we have reached the end of 's3' but 's1' or 's2' still has some characters left
            if (k == s3.length())
                return false;

            // build a lookup key
            string key = to_string(i) + "-" + to_string(j) + "-" + to_string(k);
            if (dp.count(key)) return dp[key];

            bool b1 = false, b2 = false;
            if (s1[i] == s3[k]) b1 = isInterleave(dp, s1, s2, s3, i + 1, j, k + 1);
            if (s2[j] == s3[k]) b2 = isInterleave(dp, s1, s2, s3, i, j + 1, k + 1);

            return dp[key] = b1 or b2;
        }

        bool isInterleave2(string& m, string& n, string& p) {

            if (p.length() != m.length() + n.length()) return false;

            vector<bool> dp(n.length() + 1);

            for (int i = 0; i <= m.length(); ++i) {
                for (int j = 0; j <= n.length(); ++j) {
                    if (i == 0 && j == 0) {
                        dp[j] = true;
                    }
                    else if (i == 0) {
                        dp[j] = dp[j - 1] and (n[j - 1] == p[i + j - 1]);
                    }
                    else if (j == 0) {
                        dp[j] = dp[j] and (m[i - 1] == p[i + j - 1]);
                    }
                    else {
                        dp[j] = (dp[j] and (m[i - 1] == p[i + j - 1])) or
                            (dp[j - 1] and (n[j - 1] == p[i + j - 1]));
                    }
                }
            }

            return dp[n.length()];
        }
    };
} // namespace
