// 214. Shortest Palindrome
// https://leetcode.com/problems/shortest-palindrome/

class Solution {
public:
    string shortestPalindrome(string s) {
        int length = s.length();
        if (length == 0) {
            return s;
        }

        // find longest palindrome prefix
        int left = 0;
        for (int right = length - 1; right >= 0; right--) {
            if (s[right] == s[left]) {
                ++left;
            }
        }

        // if whole string is palindrome, return original string
        if (left == length) {
            return s;
        }


        // Extract the suffix that is not part of the palindromic prefix
        string nonPalindromeSuffix = s.substr(left);
        string reverseSuffix = string(nonPalindromeSuffix.rbegin(), nonPalindromeSuffix.rend());

        // Form the shortest palindrome by prepending the reversed suffix
        return reverseSuffix +
                shortestPalindrome(s.substr(0, left)) +
                nonPalindromeSuffix;
    }
};
