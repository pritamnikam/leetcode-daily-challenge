/*
Valid Palindrome

A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, it reads the same forward and backward. Alphanumeric characters include letters and numbers.

Given a string s, return true if it is a palindrome, or false otherwise.



Example 1:

Input: s = "A man, a plan, a canal: Panama"
Output: true
Explanation: "amanaplanacanalpanama" is a palindrome.
Example 2:

Input: s = "race a car"
Output: false
Explanation: "raceacar" is not a palindrome.
Example 3:

Input: s = " "
Output: true
Explanation: s is an empty string "" after removing non-alphanumeric characters.
Since an empty string reads the same forward and backward, it is a palindrome.


Constraints:

1 <= s.length <= 2 * 105
s consists only of printable ASCII characters.

*/

using namespace std;

#include <string>
class Solution {
public:
    bool isPalindrome(string s) {
        string res;
        for (char ch : s) {
            if (isNumber(ch))
                res.push_back(ch);
            else if (isLetter(ch))
                res.push_back(toLower(ch));
        }

        // string temp = res;
        // reverse(temp.begin(), temp.end());
        return isPalindrome(res, 0, res.length() - 1);
    }

    bool isPalindrome(string& str, int start, int end) {
        if (str.empty() || start == end)
            return true;

        while (start < end) {
            if (str[start] != str[end]) {
                return false;
            }

            ++start; --end;
        }

        return true;
    }

    bool isNumber(char ch) {
        return ch >= '0' && ch <= '9';
    }

    bool isLetter(char ch) {
        return isLower(ch) || isUpper(ch);
    }

    bool isLower(char ch) {
        return (ch >= 'a' && ch <= 'z');
    }

    bool isUpper(char ch) {
        return (ch >= 'A' && ch <= 'Z');
    }

    char toLower(char ch) {
        if (isLower(ch))
            return ch;

        return 'a' + ch - 'A';

    }
};