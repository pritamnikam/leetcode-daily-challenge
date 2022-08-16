/*
387. First Unique Character in a String
https://leetcode.com/problems/first-unique-character-in-a-string/

Given a string s, find the first non-repeating character in it and return its index. 
If it does not exist, return -1.

Input: s = "leetcode"
Output: 0

Input: s = "loveleetcode"
Output: 2

Input: s = "aabb"
Output: -1

Constraints:
1 <= s.length <= 105
s consists of only lowercase English letters.

*/

using namespace std;

#include <iostream>
#include <string>
#include <unordered_map>

namespace {
	class Solution {
	public:
		int firstUniqChar(string s) {
			unordered_map<char, int> map;
			for (char ch : s)
				map[ch]++;

			for (int i = 0; i < s.size(); ++i) {
				if (map[s[i]] == 1) {
					return i;
				}
			}

			return -1;
		}
	};
}  // namespace

void testFirstUniqChar() {
	cout << "First Unique Character in a String: " << Solution().firstUniqChar("leetcode") << endl;
	cout << "First Unique Character in a String: " << Solution().firstUniqChar("loveleetcode") << endl;
	cout << "First Unique Character in a String: " << Solution().firstUniqChar("aabb") << endl;
}
