/*
520. Detect Capital
https://leetcode.com/problems/detect-capital/description/

We define the usage of capitals in a word to be right when one of the following cases holds:
- All letters in this word are capitals, like "USA".
- All letters in this word are not capitals, like "leetcode".
- Only the first letter in this word is capital, like "Google".

Given a string word, return true if the usage of capitals in it is right.

Example 1:
Input: word = "USA"
Output: true

Example 2:
Input: word = "FlaG"
Output: false

Constraints:
1 <= word.length <= 100
word consists of lowercase and uppercase English letters.

*/

using namespace std;

#include <iostream>
#include <string>

namespace {
	class Solution {
	public:
		bool detectCapitalUse(string word) {
			int n = word.length();
			bool onlyFirstLetterIsCapital = false;
			int capitalCount = 0;
			int smallCount = 0;
			for (int i = 0; i < n; ++i) {
				if (word[i] >= 'A' && word[i] <= 'Z') {
					++capitalCount;
					if (i == 0) onlyFirstLetterIsCapital = true;
				}
				else {
					++smallCount;
				}
			}
			return capitalCount == n
				|| smallCount == n
				|| (onlyFirstLetterIsCapital && smallCount == n - 1);
		}
	};
} // namespace

void testDetectCapital() {
	/*
		Example 1: Input: word = "USA", Output: true
		Example 2: Input: word = "FlaG", Output: false
	*/

	cout << "Detect Capital: " << Solution().detectCapitalUse("USA") << endl;
	cout << "Detect Capital: " << Solution().detectCapitalUse("FlaG") << endl;
}
