/*
3. Longest Substring Without Repeating Characters
https://leetcode.com/problems/longest-substring-without-repeating-characters/

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

#include <vector>
#include <iostream>
#include <unordered_map>

namespace {

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
}