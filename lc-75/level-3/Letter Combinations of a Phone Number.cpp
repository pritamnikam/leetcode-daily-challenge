/*
17. Letter Combinations of a Phone Number
https://leetcode.com/problems/letter-combinations-of-a-phone-number/

Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.

A mapping of digits to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.

Example 1:

Input: digits = "23"
Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]

Example 2:

Input: digits = ""
Output: []
Example 3:

Input: digits = "2"
Output: ["a","b","c"]


Constraints:

0 <= digits.length <= 4
digits[i] is a digit in the range ['2', '9'].

*/



using namespace std;

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

namespace {

	unordered_map<char, string> letters = { {'2', "abc"}, {'3', "def"}, {'4', "ghi"},
											{'5', "jkl"}, {'6', "mno"}, {'7', "pqrs"},
											{'8', "tuv"}, {'9', "wxyz"} };

	class Solution {
	public:
		vector<string> letterCombinations(string digits) {
			if (digits.empty()) return {};

			int current = 0;
			string path = "";
			vector<string> result;

			letterCombinations(result, digits, path, current);
			return result;
		}


		void letterCombinations(vector<string> result,
								const string& digits,
								string& path,
								int current) {
			// base case: if we reach the end
			if (current == digits.length()) {
				result.push_back(path);
				return;
			}


			// dfs: for all characters assign to the key
			for (char ch : letters[digits[current]]) {
				// add to path
				path.push_back(ch);

				// check whether we get the answer
				letterCombinations(result,
					digits,
					path,
					1 + current);

				// backtrack
				path.pop_back();
			}
		}
	};
}

void testLetterCombinations() {
	string digits = "23";
	vector<string> result = Solution().letterCombinations(digits);
}