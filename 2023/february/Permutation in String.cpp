/*
567. Permutation in String
https://leetcode.com/problems/permutation-in-string

Given two strings s1 and s2, return true if s2 contains a permutation of s1, or false otherwise.

In other words, return true if one of s1's permutations is the substring of s2.

Example 1:
Input: s1 = "ab", s2 = "eidbaooo"
Output: true
Explanation: s2 contains one permutation of s1 ("ba").

Example 2:
Input: s1 = "ab", s2 = "eidboaoo"
Output: false

Constraints:
1 <= s1.length, s2.length <= 104
s1 and s2 consist of lowercase English letters.

*/
using namespace std;

#include <unordered_map>
#include <string>
#include <iostream>

namespace {
    class Solution {
    public:
        bool checkInclusion(string s1, string s2) {
            int start = 0;
            int end = 0;

            int k = s1.length();
            int distinctLetters = 0;
            unordered_map<char, int> window;

            for (char ch : s1) {
                window[ch]++;
                if (window[ch] == 1) {
                    distinctLetters++;
                }
            }
            while (end < s2.length()) {
                auto it = window.find(s2[end]);
                if (it != window.end()) {
                    window[s2[end]]--;
                    if (window[s2[end]] == 0) {
                        distinctLetters--;
                    }
                }

                if (end - start + 1 < k) {
                    end++;
                }
                else {
                    if (distinctLetters == 0) {
                        return true;
                    }

                    if (window.find(s2[start]) != window.end()) {
                        window[s2[start]]++;
                        if (window[s2[start]] == 1)
                            distinctLetters++;
                    }

                    start++;
                    end++;
                }

            }

            return false;
        }
    };
}  // namespace


void testPermutationInString() {
    //  Input: s1 = "ab", s2 = "eidbaooo", Output: true
    cout << "Permutation in String: " << Solution().checkInclusion("ab", "eidbaooo") << endl;
}
