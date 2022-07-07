/*
97. Interleaving String
URL: https://leetcode.com/problems/interleaving-string/

Given strings s1, s2, and s3, find whether s3 is formed by an interleaving of s1 and s2.

An interleaving of two strings s and t is a configuration where they are divided into non-empty substrings such that:

s = s1 + s2 + ... + sn
t = t1 + t2 + ... + tm
|n - m| <= 1
The interleaving is s1 + t1 + s2 + t2 + s3 + t3 + ... or t1 + s1 + t2 + s2 + t3 + s3 + ...
Note: a + b is the concatenation of strings a and b.

Example 1:
Input: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac"
Output: true

Example 2:
Input: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbbaccc"
Output: false

Example 3:
Input: s1 = "", s2 = "", s3 = ""
Output: true

Constraints:

0 <= s1.length, s2.length <= 100
0 <= s3.length <= 200
s1, s2, and s3 consist of lowercase English letters.

*/

#include <string>
#include <unordered_map>

using namespace std;

namespace {
  
    class Solution {
      public:
        bool isInterleave(string s1, string s2, string s3) {
          unordered_map<string, bool> dp;
          return isInterleave(dp, s1, s2, s3, 0, 0, 0);
        }
      
      
      private:
        bool isInterleave(unordered_map<string, bool>& dp,
                          string s1, string s2, string s3,
                          int i, int j, int k) {
          // if we have reached the end of the all the strings
          if (i == s1.length() &&
              j == s2. length() &&
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
  };
} // namespace

void testInterleavingStrings() {
  string s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac";
  cout << "Interleaving Strings: " << Soluton().isInterleave(s1, s2, s3) << endl; // true
  
  s1 = "aabcc", s2 = "dbbca", s3 = "aadbbbaccc";
  cout << "Interleaving Strings: " << Soluton().isInterleave(s1, s2, s3) << endl; // false
  
  s1 = "", s2 = "", s3 = "";
  cout << "Interleaving Strings: " << Soluton().isInterleave(s1, s2, s3) << endl; // true
}
