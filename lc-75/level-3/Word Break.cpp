/*
139. Word Break

Given a string s and a dictionary of strings wordDict, return true if s can be segmented into a space-separated sequence of one or more dictionary words.

Note that the same word in the dictionary may be reused multiple times in the segmentation.



Example 1:

Input: s = "leetcode", wordDict = ["leet","code"]
Output: true
Explanation: Return true because "leetcode" can be segmented as "leet code".
Example 2:

Input: s = "applepenapple", wordDict = ["apple","pen"]
Output: true
Explanation: Return true because "applepenapple" can be segmented as "apple pen apple".
Note that you are allowed to reuse a dictionary word.
Example 3:

Input: s = "catsandog", wordDict = ["cats","dog","sand","and","cat"]
Output: false


Constraints:

1 <= s.length <= 300
1 <= wordDict.length <= 1000
1 <= wordDict[i].length <= 20
s and wordDict[i] consist of only lowercase English letters.
All the strings of wordDict are unique.

*/

using namespace std;

#include <iostream>

#include <vector>
#include <unordered_map>


namespace {
	class Solution {
		unordered_map<string, bool> dp;

	public:
		bool wordBreak(string s, vector<string>& wordDict) {
			for (string& word : wordDict)
				dp[word] = true;

			return solve(s);
		}

	private:
		bool solve(string& s) {
			if (dp.find(s) != dp.end()) return dp[s];

			if (s.length() == 1)
				return false;

			string left, right;
			for (int i = 1; i < s.length(); ++i) {
				left = s.substr(0, i);
				right = s.substr(i, s.length() - i);

				if (dp[left]) {
					dp[right] = solve(right);
					if (dp[left] && dp[right])
						return dp[s] = true;
				}
			}
			return dp[s] = false;
		}
	};
} // namespace


void testWordBreak() {
	string s = "leetcode";
	vector<string> wordDict = { "leet", "code" };
	cout << "Word break: " << Solution().wordBreak(s, wordDict) << endl;

	s = "applepenapple";
	wordDict = { "apple","pen" };
	cout << "Word break: " << Solution().wordBreak(s, wordDict) << endl;


	s = "catsandog";
	wordDict = { "cats","dog","sand","and","cat" };
	cout << "Word break: " << Solution().wordBreak(s, wordDict) << endl;
}