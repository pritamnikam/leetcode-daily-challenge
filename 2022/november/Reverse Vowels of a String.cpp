/*
345. Reverse Vowels of a String
https://leetcode.com/problems/reverse-vowels-of-a-string/

Given a string s, reverse only all the vowels in the string and return it.

The vowels are 'a', 'e', 'i', 'o', and 'u', and they can appear in both lower and upper cases, more than once.

Example 1:
Input: s = "hello"
Output: "holle"

Example 2:
Input: s = "leetcode"
Output: "leotcede"

Constraints:
1 <= s.length <= 3 * 105
s consist of printable ASCII characters.

*/

using namespace std;

#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>

namespace {

	class Solution {
	public:
		string reverseVowels(string s) {
			int left = 0, 
				right = s.length() - 1;
			while (left <= right) {
				// both char are vowel
				if (isVowel(s[left]) && isVowel(s[right])) {
					swap(s[left], s[right]);
					++left;
					--right;
				}

				if (left < s.length() - 1 && !isVowel(s[left])) {
					++left;
				}


				if (right >= 0 && !isVowel(s[right])) {
					--right;
				}
			}

			return s;
		}

	private:
		const unordered_set<char> vowel = { 'a','e','i','o','u', 'A', 'E', 'I', 'O', 'U' };

		bool isVowel(char ch) {
			return vowel.count(ch) != 0;
		}
	};

} // namespace


void testReverseVowelsOfString() {
	// Input: s = "leetcode" | Output: "leotcede"
	cout << "Reverse Vowels of a String 'leetcode': " << Solution().reverseVowels("leetcode") << endl;
}
