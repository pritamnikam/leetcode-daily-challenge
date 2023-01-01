/*
290. Word Pattern
https://leetcode.com/problems/word-pattern/

Given a pattern and a string s, find if s follows the same pattern.

Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty word in s.

Example 1:
Input: pattern = "abba", s = "dog cat cat dog"
Output: true

Example 2:
Input: pattern = "abba", s = "dog cat cat fish"
Output: false

Example 3:
Input: pattern = "aaaa", s = "dog cat cat dog"
Output: false

Constraints:
1 <= pattern.length <= 300
pattern contains only lower-case English letters.
1 <= s.length <= 3000
s contains only lowercase English letters and spaces ' '.
s does not contain any leading or trailing spaces.
All the words in s are separated by a single space.
*/

using namespace std;

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <sstream>

/*
APPROACH :
- Use two maps, one maps the letters of pattern to index+1 & the other maps the words in s to index+1.
- Use istringstream to extract words from s & i to traverse pattern.
- Return true if the values of both the keys ( m1[pattern[i]] & m2[word] ) are equal && i reaches pattern.size() & stops. (ie; No. of words in s = pattern.size() ), otherwise false.

Time Complexity : O(m) - m = No. of words in s.

Space Complexity : O(m)
*/

namespace {
    

    class Solution {
    public:
        bool wordPattern(string pattern, string s) {
            // maps to hold counts
            unordered_map<char, int> patternCounMap;
            unordered_map<string, int> stringCountMap;

            // string tokenization
            istringstream in(s);
            int n = pattern.size();
            int i = 0;

            // for every word and char:
            for (string word; in >> word; i++) {
                // If it reaches end before all the words in string 's' are traversed
                // or, if values of keys : pattern[i] & word don't match return false
                if (i == n ||
                    patternCounMap[pattern[i]] != stringCountMap[word]) {
                    return false;
                }

                // Otherwise map to both to a value i+1
                patternCounMap[pattern[i]] = stringCountMap[word] = i + 1;
            }

            // both the lengths should be equal
            return i == n;
        }
    };

}  // namespace


void testWordPattern() {
    /*
        Example 1:
        Input: pattern = "abba", s = "dog cat cat dog"
        Output: true
    */

    string pattern = "abba", s = "dog cat cat dog";
    cout << "Word Pattern: " << Solution().wordPattern(pattern, s) << endl;
}
