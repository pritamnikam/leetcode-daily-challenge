/*
859. Buddy Strings
https://leetcode.com/problems/buddy-strings/description/

Given two strings s and goal, return true if you can swap two letters in s so the result is equal to goal, otherwise, return false.

Swapping letters is defined as taking two indices i and j (0-indexed) such that i != j and swapping the characters at s[i] and s[j].

For example, swapping at indices 0 and 2 in "abcd" results in "cbad".


Example 1:

Input: s = "ab", goal = "ba"
Output: true
Explanation: You can swap s[0] = 'a' and s[1] = 'b' to get "ba", which is equal to goal.
Example 2:

Input: s = "ab", goal = "ab"
Output: false
Explanation: The only letters you can swap are s[0] = 'a' and s[1] = 'b', which results in "ba" != goal.
Example 3:

Input: s = "aa", goal = "aa"
Output: true
Explanation: You can swap s[0] = 'a' and s[1] = 'a' to get "aa", which is equal to goal.


Constraints:

1 <= s.length, goal.length <= 2 * 104
s and goal consist of lowercase letters.
*/

using namespace std;

#include <string>
#include <vector>

namespace {

    class Solution {
    public:
        bool buddyStrings(string s, string goal) {
            // case 1:
            if (s.length() != goal.length()) return false;

            // case 2:
            if (s == goal) {
                
                vector<int> vt(26, 0);
                for (char ch : s) {
                    vt[ch - 'a']++;
                    if (vt[ch - 'a'] > 1) return true;
                }
                return false;
            }

            // case 3;
            int firstMismatch = -1;
            int secondMismatch = -1;

            for (int i = 0; i < s.length(); i++) {
                if (s[i] != goal[i]) {
                    if (firstMismatch == -1) {
                        firstMismatch = i;
                    }
                    else if (secondMismatch == -1) {
                        secondMismatch = i;
                    }
                    else {
                        return false;
                    }
                }
            }
            if (secondMismatch == -1) return false;

            return s[firstMismatch] == goal[secondMismatch] && goal[firstMismatch] == s[secondMismatch];
        }
    };
}
