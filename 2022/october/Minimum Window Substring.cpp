/*
76. Minimum Window Substring
https://leetcode.com/problems/minimum-window-substring/

Given two strings s and t of lengths m and n respectively, return the minimum window substring of s such that every character in t (including duplicates) is included in the window. If there is no such substring, return the empty string "".

The testcases will be generated such that the answer is unique.

A substring is a contiguous sequence of characters within the string.



Example 1:

Input: s = "ADOBECODEBANC", t = "ABC"
Output: "BANC"
Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C' from string t.
Example 2:

Input: s = "a", t = "a"
Output: "a"
Explanation: The entire string s is the minimum window.
Example 3:

Input: s = "a", t = "aa"
Output: ""
Explanation: Both 'a's from t must be included in the window.
Since the largest window of s only has one 'a', return empty string.


Constraints:

m == s.length
n == t.length
1 <= m, n <= 105
s and t consist of uppercase and lowercase English letters.


Follow up: Could you find an algorithm that runs in O(m + n) time?


*/

using namespace std;

#include <iostream>
#include <vector>
#include <unordered_map>

namespace {
	class Solution {
	public:
		string minWindow(string s, string t) {
			// corner case:
			if (s.empty()
				|| t.empty()
				|| s.length() < t.length()) {
				return "";
			}

			unordered_map<char, int> charFreqMap;
			for (char ch : t) {
				charFreqMap[ch]++;
			}

			int matched = 0;
			int start = -1;

			int windowSize = s.length();
			int windowStart = 0;
			for (int windowEnd = 0; windowEnd < s.length(); ++windowEnd) {
				char rightChar = s[windowEnd];
				if (charFreqMap.count(rightChar)) {
					charFreqMap[rightChar]--;
					if (charFreqMap[rightChar] == 0)
						++matched;
				}

				// keep shrinking the window from left to get minimum size of window that has all char from 't'.
				while (matched == charFreqMap.size()) {
					// update window size
					int currentWindowSize = windowEnd - windowStart + 1;
					if (windowSize >= currentWindowSize) {
						start = windowStart;
						windowSize = currentWindowSize;
					}

					char leftChar = s[windowStart];
					if (charFreqMap.count(leftChar)) {
						if (charFreqMap[leftChar] == 0)
							--matched;

						charFreqMap[leftChar]++;
					}

					++windowStart;
				}
			}
			return (start == -1) 
				? ""
				: s.substr(start, windowSize);
		}
	};
}  // namespace
