/*
159. Longest Substring with At Most Two Distinct Characters
https://leetcode.com/problems/longest-substring-with-at-most-two-distinct-characters/

Given a string s, return the length of the longest substring that contains at most two distinct characters.



Example 1:

Input: s = "eceba"
Output: 3
Explanation: The substring is "ece" which its length is 3.
Example 2:

Input: s = "ccaabbb"
Output: 5
Explanation: The substring is "aabbb" which its length is 5.


Constraints:

1 <= s.length <= 105
s consists of English letters.

*/
using namespace std;

#include <unordered_map>
#include <string>
#include <vector>

namespace {
    class Solution {
    public:
        int lengthOfLongestSubstringTwoDistinct(string s) {
            int windowSize = 0;
            unordered_map<char, int> charFreqMap;
            for (int windowStart = 0, windowEnd = 0; windowEnd < s.length(); ++windowEnd) {
                charFreqMap[s[windowEnd]]++;

                if (charFreqMap.size() > 2) {
                    charFreqMap[s[windowStart]]--;
                    if (charFreqMap[s[windowStart]] == 0)
                        charFreqMap.erase(s[windowStart]);

                    ++windowStart;
                }

                windowSize = max(windowSize, windowEnd - windowStart + 1);

            }

            return windowSize;
        }
    };
}