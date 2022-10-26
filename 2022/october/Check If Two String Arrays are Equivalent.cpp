/*
1662. Check If Two String Arrays are Equivalent
https://leetcode.com/problems/check-if-two-string-arrays-are-equivalent/

Given two string arrays word1 and word2, return true if the two arrays represent the same string, and false otherwise.
A string is represented by an array if the array elements concatenated in order forms the string.

Example 1:
Input: word1 = ["ab", "c"], word2 = ["a", "bc"]
Output: true
Explanation:
word1 represents string "ab" + "c" -> "abc"
word2 represents string "a" + "bc" -> "abc"
The strings are the same, so return true.

Example 2:
Input: word1 = ["a", "cb"], word2 = ["ab", "c"]
Output: false

Example 3:
Input: word1  = ["abc", "d", "defg"], word2 = ["abcddefg"]
Output: true

Constraints:
1 <= word1.length, word2.length <= 103
1 <= word1[i].length, word2[i].length <= 103
1 <= sum(word1[i].length), sum(word2[i].length) <= 103
word1[i] and word2[i] consist of lowercase letters.

*/

using namespace std;
#include <vector>
#include <string>

namespace {
    class Solution {
    public:
        bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
            string str1, str2;
            for (string& word : word1) {
                str1 += word;
            }

            for (string& word : word2) {
                str2 += word;
            }

            return str1 == str2;
        }

        bool arrayStringsAreEqual2(vector<string>& word1, vector<string>& word2) {
            int i = 0, j = 0; // word count
            int m = 0, n = 0; // char count

            while (i < word1.size() && j < word2.size()) {
                if (word1[i][m] != word2[j][n]) {
                    return false;
                }

                ++m; ++n;

                if (m >= word1[i].size()) {
                    ++i;
                    m = 0;
                }

                if (n >= word2[j].size()) {
                    ++j;
                    n = 0;
                }
            }

            return i == word1.size() && j == word2.size();
        }
    };
}
