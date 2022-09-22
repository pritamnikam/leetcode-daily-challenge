/*
557. Reverse Words in a String III
https://leetcode.com/problems/reverse-words-in-a-string-iii/

Given a string s, reverse the order of characters in each word within a sentence while still preserving whitespace and initial word order.



Example 1:

Input: s = "Let's take LeetCode contest"
Output: "s'teL ekat edoCteeL tsetnoc"
Example 2:

Input: s = "God Ding"
Output: "doG gniD"


Constraints:

1 <= s.length <= 5 * 104
s contains printable ASCII characters.
s does not contain any leading or trailing spaces.
There is at least one word in s.
All the words in s are separated by a single space.

*/

using namespace std;

#include <iostream>
#include <vector>
#include <string>
#include <sstream>

namespace {
	class Solution {
	public:
		string reverseWords(string s) {
			int i = 0, 
				j = 0;

			for (; j < s.length(); ++j) {
				if (s[j] == ' ') {
					reverseString(s, i, j - 1);
					i = j + 1;
				}
			}

			reverseString(s, i, j - 1);
			return s;
		}

	private:
		void reverseString(string& s, int i, int j) {
			while (i < j) {
				swap(s, i, j);
				++i;
				--j;
			}
		}

		void swap(string& s, int i, int j) {
			char c = s[i];
			s[i] = s[j];
			s[j] = c;
		}
	};
}
