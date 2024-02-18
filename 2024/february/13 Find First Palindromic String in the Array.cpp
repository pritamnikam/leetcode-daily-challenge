// 2108. Find First Palindromic String in the Array
// https://leetcode.com/problems/find-first-palindromic-string-in-the-array/

class Solution {
    bool isPalindrome(string& str) {
        int n = str.length();
        int i = 0, j = n - 1;
        while (i < j) {
            if (str[i] != str[j]) {
                return false;
            }
            ++i;
            --j;
        }

        return true;
    }
public:
    string firstPalindrome(vector<string>& words) {
        for (string& str: words) {
            if (isPalindrome(str)) {
                return str;
            }
        }
        return string();
    }
};
