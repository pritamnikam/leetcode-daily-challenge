/*
14. Longest Common Prefix
Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".

Example 1:
Input: strs = ["flower","flow","flight"]
Output: "fl"

Example 2:
Input: strs = ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.


Constraints:
1 <= strs.length <= 200
0 <= strs[i].length <= 200
strs[i] consists of only lowercase English letters.
*/

using namespace std;

#include <iostream>
#include <string>
#include <vector>

namespace {
	class Solution {
	public:
		// Divide & Conquer
		string longestCommonPrefix(vector<string>& strs) {
			if (strs.empty()) return "";

			return longestCommonPrefix(strs, 0, strs.size() - 1);
		}

	private:
		string longestCommonPrefix(vector<string>& strs, int left, int right) {
			if (left == right)
				return strs[left];

			int mid = left + (right - left) / 2;
			string l = longestCommonPrefix(strs, left, mid);
			string r = longestCommonPrefix(strs, mid+1, right);

			return longestCommonPrefix(l, r);
		}

		string longestCommonPrefix(string& a, string& b) {
			int i = 0, n = min(a.length(), b.length());
			while (i < n && a[i] == b[i]) {
				++i;
			}

			return a.substr(0, i);
		}
	};
}

void testLongestCommonPrefix() {
	vector<string> strs = { "flower", "flow", "flight" };
	cout << "Longest common prefix: " << Solution().longestCommonPrefix(strs) << endl;


	strs = { "dog","racecar","car" };
	cout << "Longest common prefix: " << Solution().longestCommonPrefix(strs) << endl;
}
