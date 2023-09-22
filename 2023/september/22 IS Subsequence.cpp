// 392. Is Subsequence
// https://leetcode.com/problems/is-subsequence/


using namespace std;

#include <iostream>
#include <vector>
#include <string>

namespace {

class Solution {
public:
    /*
    bool isSubsequence(string s, string t) {
        int m = s.length();
        int n = t.length();
        int LCS_table[m + 1][n + 1];


          // Building the mtrix in bottom-up way
          for (int i = 0; i <= m; i++) {
            for (int j = 0; j <= n; j++) {
              if (i == 0 || j == 0)
                LCS_table[i][j] = 0;
              else if (s[i - 1] == t[j - 1])
                LCS_table[i][j] = LCS_table[i - 1][j - 1] + 1;
              else
                LCS_table[i][j] = max(LCS_table[i - 1][j], LCS_table[i][j - 1]);
            }
          }
        
        return LCS_table[m][n] == m;

        }*/
    /*
    bool isSubsequence(string s, string t) {
        int j = 0;
        for (int i = 0; i < t.length(); ++i) {
            if (t[i] == s[j])
                ++j;
        }

        return (j == s.length());
    }
    */
    
    /*
    bool isSubsequence(string s, string t) {
        return isSubsequence(s, t, s.length(), t.length());
    }

    bool isSubsequence(string& s, string& t, int m, int n) {
        if (m == 0) return true;
        if (n == 0) return false;

        if (s[m - 1] == t[n - 1]) {
            return isSubsequence(s, t, m - 1, n - 1);
        }

        return isSubsequence(s, t, m, n - 1);
    }
    */
    
    bool isSubsequence1(string s, string t) {
        vector<vector<int>>dp(s.length() + 1, 
                              vector<int>(t.length() + 1, -1));
        
        int result = isSubsequence(dp, s, t, s.length(), t.length());
        if (result == s.length())
            return true;

        return false;
    }

    int isSubsequence(vector<vector<int>> dp, 
                      string& s, string& t, 
                      int m, int n) {
        if (m == 0) return 0;
        if (n == 0) return 0;

        if (dp[m][n] != -1)
            return dp[m][n];

        if (s[m - 1] == t[n - 1]) {
            dp[m][n] = 1 + isSubsequence(dp, s, t, m - 1, n - 1);
            return dp[m][n];
        }

        dp[m][n] = isSubsequence(dp, s, t, m, n - 1);
        return dp[m][n];
    }
    
    
    bool isSubsequence(string s, string t) {
        int rows = s.length();
        int cols = t.length();
        
        if (rows == 0) return true;
        
        vector<vector<int>> dp(rows + 1, 
                               vector<int>(cols+1, 0));
        
        for (int i = 1; i <= rows; ++i) {
            for (int j = 1; j <= cols; ++j) {
                if (s[i-1] == t[j-1]) {
                    dp[i][j] = dp[i-1][j-1] + 1;
                } else {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
            
            if (rows == dp[i][cols]) return true;
        }
        
        return false;
    }
};

} // namespace
