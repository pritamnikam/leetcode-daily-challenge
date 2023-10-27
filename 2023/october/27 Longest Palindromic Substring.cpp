// Lon5. gest Palindromic Substring
// https://leetcode.com/problems/longest-palindromic-substring/submissions/1085035724/

using namespace std;

#include <iostream>
#include <string>

namespace {
class Solution {
public:
string longestPalindrome(string s) {
        if (s.empty()) 
            return "";

        int start = 0, end = 0, maxLen = 0;
        for (int i = 0; i < s.length(); i++) {
            int len1 = expandAroundCenter(s, i, i);     // odd length
            int len2 = expandAroundCenter(s, i, i + 1); // even length
            int len = max(len1, len2);
            if (len > end - start) {
                start = i - (len - 1) / 2;
                end = i + len / 2;
            }
            
            maxLen = max(maxLen, len);
        }
        return s.substr(start, maxLen);
    }

    int expandAroundCenter(string s, int left, int right) {
        int L = left, R = right;
        while (L >= 0 && R < s.length() && s[L] == s[R]) {
            L--;
            R++;
        }
        return R - L - 1;
    }
    };
    }
