/*
1832. Check if the Sentence Is Pangram
https://leetcode.com/problems/check-if-the-sentence-is-pangram/

A pangram is a sentence where every letter of the English alphabet appears at least once.

Given a string sentence containing only lowercase English letters, return true if sentence is a pangram, or false otherwise.

Example 1:
Input: sentence = "thequickbrownfoxjumpsoverthelazydog"
Output: true
Explanation: sentence contains at least one of every letter of the English alphabet.

Example 2:
Input: sentence = "leetcode"
Output: false
 

Constraints:
1 <= sentence.length <= 1000
sentence consists of lowercase English letters.
*/

using namespace std;

#include <iostream>
#include <set>

namespace {

  class Solution {
public:
    bool checkIfPangram(string sentence) {
        set<char> alphabets(sentence.begin(), sentence.end());
        return alphabets.size() == 26;
    }
};

} // namespace
