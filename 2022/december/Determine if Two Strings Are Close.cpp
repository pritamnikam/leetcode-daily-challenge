/*
1657. Determine if Two Strings Are Close
https://leetcode.com/problems/determine-if-two-strings-are-close/

Two strings are considered close if you can attain one from the other using the following operations:

Operation 1: Swap any two existing characters.
For example, abcde -> aecdb

Operation 2: Transform every occurrence of one existing character into another existing character, and do the same with the other character.
For example, aacabb -> bbcbaa (all a's turn into b's, and all b's turn into a's)

You can use the operations on either string as many times as necessary.

Given two strings, word1 and word2, return true if word1 and word2 are close, and false otherwise.

Example 1:
Input: word1 = "abc", word2 = "bca"
Output: true
Explanation: You can attain word2 from word1 in 2 operations.
Apply Operation 1: "abc" -> "acb"
Apply Operation 2: "acb" -> "bca"

Example 2:
Input: word1 = "a", word2 = "aa"
Output: false
Explanation: It is impossible to attain word2 from word1, or vice versa, in any number of operations.

Example 3:
Input: word1 = "cabbba", word2 = "abbccc"
Output: true

Explanation: You can attain word2 from word1 in 3 operations.
Apply Operation 1: "cabbba" -> "caabbb"
Apply Operation 2: "caabbb" -> "baaccc"
Apply Operation 2: "baaccc" -> "abbccc"

Constraints:
1 <= word1.length, word2.length <= 105
word1 and word2 contain only lowercase English letters.

Idea : Two thing's Need to check
1. Frequency of Char need's to be same there both of string as we can do Transform every occurrence of one existing character into another existing character
2. All the unique char which there in String1 need's to there as well In string2
*/

using namespace std;

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

namespace {

    class Solution {
    public:
        bool closeStrings(string word1, string word2) {
            set<char> s1, s2;
            vector<int> m1(26, 0), m2(26, 0);

            for (char ch : word1) {
                s1.insert(ch);
                m1[ch-'a']++;
            }

            for (char ch : word2) {
                s2.insert(ch);
                m2[ch - 'a']++;
            }

            sort(m1.begin(), m1.end());
            sort(m2.begin(), m2.end());

            return s1 == s2 && m1 == m2;
        }
    };

}  // namespace


void testDetermineIfTwoStringsAreClose() {
    // Input: word1 = "abc", word2 = "bca", Output: true
    cout << "Determine if Two Strings Are Close: " << Solution().closeStrings("abc", "bca") << endl;

    // Input: word1 = "a", word2 = "aa", Output: false
    cout << "Determine if Two Strings Are Close: " << Solution().closeStrings("a", "aa") << endl;

    // Input: word1 = "cabbba", word2 = "abbccc", Output: true
    cout << "Determine if Two Strings Are Close: " << Solution().closeStrings("cabbba", "abbccc") << endl;
}
