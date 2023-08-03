/*
17. Letter Combinations of a Phone Number
Medium
16.3K
875
Companies
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

class Solution {
    
    unordered_map<char, string> letters = { {'2', "abc"}, {'3', "def"}, {'4', "ghi"},
                                            {'5', "jkl"}, {'6', "mno"}, {'7', "pqrs"},
                                            {'8', "tuv"}, {'9', "wxyz"} };
    
    
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) {
            return {};
        }
        vector<string> result;
        letterCombinations(digits, result, "", 0);
        return result;
    }
    
    void letterCombinations(const string& digits, 
                            vector<string>& result, 
                            string currentString, 
                            int currentIndex) {
        // if we reach the end
        if (currentIndex == digits.length()) {
            result.emplace_back(currentString);
            return;
        }
        
        
        // for all characters assign to the key
        for (char ch: letters[digits[currentIndex]]) {
            letterCombinations(digits,
                               result, 
                               currentString + ch, 
                               currentIndex + 1);
        }
    }
};
