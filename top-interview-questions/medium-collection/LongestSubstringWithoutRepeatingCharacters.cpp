/*
Longest Substring Without Repeating Characters

Given a string s, find the length of the longest substring without repeating characters.

Example 1:
Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.

Example 2:
Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.

Example 3:
Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.


Constraints:
0 <= s.length <= 5 * 104
s consists of English letters, digits, symbols and spaces.

*/

using namespace std;

#include <string>
#include <unordered_map>

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxLength = 0;
        // TODO: Write your code here
        int i = 0, j = 0, count = 0, n = s.length();
        unordered_map<char, int> mp;

        for (j = 0; j < n; ++j) {
            char ch = s[j];

            // new char is already present in map.
            // it's indication that window needs to be shrinked from start
            if (mp.count(ch)) {
                // since the new character is already part of window
                // to continue the quest, reset the start of window to the
                // next to previously stored position of 'ch'
                i = max(i, mp[ch] + 1);
            }

            // update the new position for the ch
            mp[ch] = j;

            // calculate the window size
            maxLength = max(maxLength, j - i + 1);
        }

        return maxLength;
    }
};


class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> charPositionMap;
        int maxLength = 0, windowStart = 0;
        for (int windowEnd = 0; windowEnd < s.length(); ++windowEnd) {
            char ch = s[windowEnd];
            if (charPositionMap.count(ch)) {
                windowStart = max(windowStart, charPositionMap[ch] + 1);
            }

            charPositionMap[ch] = windowEnd;
            maxLength = max(maxLength, windowEnd - windowStart + 1);
        }

        return maxLength;
    }
};