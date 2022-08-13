/*
30. Substring with Concatenation of All Words
https://leetcode.com/problems/substring-with-concatenation-of-all-words/

You are given a string s and an array of strings words of the same length. 
Return all starting indices of substring(s) in s that is a concatenation of each word in words exactly once, 
in any order, and without any intervening characters.

You can return the answer in any order.



Example 1:

Input: s = "barfoothefoobarman", words = ["foo","bar"]
Output: [0,9]
Explanation: Substrings starting at index 0 and 9 are "barfoo" and "foobar" respectively.
The output order does not matter, returning [9,0] is fine too.
Example 2:

Input: s = "wordgoodgoodgoodbestword", words = ["word","good","best","word"]
Output: []
Example 3:

Input: s = "barfoofoobarthefoobarman", words = ["bar","foo","the"]
Output: [6,9,12]


Constraints:

1 <= s.length <= 104
1 <= words.length <= 5000
1 <= words[i].length <= 30
s and words[i] consist of lowercase English letters.

*/


using namespace std;

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>
#include <string>

namespace {
	class Solution {
	public:
		
		vector<int> findSubstring1(string s, vector<string>& words) {
			int n = s.size(),
				total = words.size(),
				len = words[0].size();

			unordered_map<string, int> freq;
			for (auto w : words) {
				freq[w]++;
			}

			vector<int> answer;
			for (int i = 0; i < (n - total * len + 1); i++) {
				int j = i;
				unordered_map<string, int> stats = freq;
				int covered = 0;

				while (covered < total && (j + len - 1) < n) {
					string word = s.substr(j, len);
					if (stats.find(word) != stats.end() && --stats[word] >= 0) {
						covered++;
						j += len;
					}
					else break;
				}
				if (covered == total) answer.push_back(i);
			}

			return answer;
		}


		vector<int> findSubstring(string s, vector<string>& words) {
			// corner cases:
			if (s.empty() || words.empty()) return {};

			// word frequency counts
			unordered_map<string, int> counts;
			for (string& word : words)
				counts[word]++;


			vector<int> answer;
			int sLen = s.length();
			int num = words.size();
			int wordLen = words[0].length();

			int wordsConcatLen = num * wordLen;
			for (int i = 0; i < sLen - wordsConcatLen + 1; ++i) {
				string sub = s.substr(i, i + wordsConcatLen);
				if (isConcat(sub, counts, wordLen)) {
					answer.push_back(i);
				}
			}
			return answer;
		}


	private:
		bool isConcat(const string& str, unordered_map<string, int>& counts, int wordLen) {
			unordered_map<string, int> seen;
			for (int i = 0; i < str.length(); i += wordLen) {
				string word = str.substr(i, i + wordLen);
				seen[word]++;
			}

			return seen == counts;
		}
	};
}  // namespace


void testFindSubstring() {
	string s = "barfoothefoobarman";
	vector<string> words = { "foo", "bar" };

	vector<int> output = Solution().findSubstring(s, words);
}
