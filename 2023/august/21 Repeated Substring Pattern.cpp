/*
459. Repeated Substring Pattern
https://leetcode.com/problems/repeated-substring-pattern/description/

Given a string s, check if it can be constructed by taking a substring of it and appending multiple copies of the substring together.

Example 1:

Input: s = "abab"
Output: true
Explanation: It is the substring "ab" twice.
Example 2:

Input: s = "aba"
Output: false
Example 3:

Input: s = "abcabcabcabc"
Output: true
Explanation: It is the substring "abc" four times or the substring "abcabc" twice.


Constraints:

1 <= s.length <= 104
s consists of lowercase English letters.
*/
using namespace std;

#include <iostream>
#include <string>


namespace {
	class Solution {
	public:
		bool repeatedSubstringPattern(string s) {
			string target = s + s;

			// if removing first and last char from concatenated string
			// has substring |s|, we have Repeated Substring Pattern.
			if (target.substr(1, target.size() - 2).find(s) != -1) {
				return true;
			}

			return false;
		}
	};
}
