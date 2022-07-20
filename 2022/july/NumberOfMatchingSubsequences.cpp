/*
792. Number of Matching Subsequences
https://leetcode.com/problems/number-of-matching-subsequences/

Given a string s and an array of strings words, return the number of words[i] that is a subsequence of s.

A subsequence of a string is a new string generated from the original string with some characters 
(can be none) deleted without changing the relative order of the remaining characters.

For example, "ace" is a subsequence of "abcde".


Example 1:
Input: s = "abcde", words = ["a","bb","acd","ace"]
Output: 3
Explanation: There are three strings in words that are a subsequence of s: "a", "acd", "ace".

Example 2:
Input: s = "dsahjpjauf", words = ["ahjpjau","ja","ahbwzgqnuk","tnmlanowax"]
Output: 2


Constraints:
1 <= s.length <= 5 * 104
1 <= words.length <= 5000
1 <= words[i].length <= 50
s and words[i] consist of only lowercase English letters.

*/

using namespace std;

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

namespace {
	class Solution {
	public:
		int numMatchingSubseq(string s, vector<string>& words) {
			// char => {{str1, #match}, {str2, #match}}
			unordered_map<char, list<pair<string, int>>> heads;

			for (string& word : words) {
				heads[word[0]].push_back({ word, 0 });
			}

			// answers
			int answer = 0;

			for (char ch : s) {
				// get matches
				list<pair<string, int>> matchingBuckets = heads[ch];
				heads[ch] = {};

				for (auto& bucket : matchingBuckets) {
					bucket.second++;

					// if all characters found, we have the answer
					if (bucket.second == bucket.first.length()) {
						++answer;
					}
					else {
						// insert to the bucket list next matching char.
						heads[bucket.first[bucket.second]].push_back(bucket);
					}
				}

				matchingBuckets.clear();
			}

			return answer;
		}
	};
}

void testNumberOfMatchingSubsequences() {
	string s = "abcde";
	vector<string> words = { "a", "bb", "acd", "ace" };

	cout << "Number of matching subsequences: " << Solution().numMatchingSubseq(s, words) << endl;
}
