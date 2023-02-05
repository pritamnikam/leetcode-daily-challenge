/*
* 
438. Find All Anagrams in a String
https://leetcode.com/problems/find-all-anagrams-in-a-string/description/

Given two strings s and p, return an array of all the start indices of p's anagrams in s. You may return the answer in any order.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.



Example 1:

Input: s = "cbaebabacd", p = "abc"
Output: [0,6]
Explanation:
The substring with start index = 0 is "cba", which is an anagram of "abc".
The substring with start index = 6 is "bac", which is an anagram of "abc".
Example 2:

Input: s = "abab", p = "ab"
Output: [0,1,2]
Explanation:
The substring with start index = 0 is "ab", which is an anagram of "ab".
The substring with start index = 1 is "ba", which is an anagram of "ab".
The substring with start index = 2 is "ab", which is an anagram of "ab".


Constraints:

1 <= s.length, p.length <= 3 * 104
s and p consist of lowercase English letters.


*/
using namespace std;

#include <vector>
#include <unordered_map>
#include <string>

namespace {
    class Solution {
    public:
        vector<int> findAnagrams(string s, string p) {
            int start = 0;
            int end = 0;

            int k = p.length();

            unordered_map<char, int> window;
            int distinctLetters = 0;

            vector<int> answer;

            for (char ch : p) {
                window[ch]++;
                if (window[ch] == 1)
                    distinctLetters++;
            }


            while (end < s.length()) {
                auto it = window.find(s[end]);
                if (it != window.end()) {
                    window[s[end]]--;
                    if (window[s[end]] == 0)
                        distinctLetters--;
                }


                if (end - start + 1 < k) {
                    ++end;
                }
                else {
                    if (distinctLetters == 0) {
                        answer.push_back(start);
                    }

                    if (window.find(s[start]) != window.end()) {
                        window[s[start]]++;
                        if (window[s[start]] == 1)
                            distinctLetters++;
                    }

                    ++start;
                    ++end;
                }
            }

            return answer;
        }
    };
} // namespace

void testFindAllAnagramsInAString() {
    // Input: s = "cbaebabacd", p = "abc" | Output: [0, 6]
    vector<int> output = Solution().findAnagrams("cbaebabacd", "abc");
}
