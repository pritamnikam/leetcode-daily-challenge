/*
242. Valid Anagram
https://leetcode.com/problems/valid-anagram/

Given two strings s and t, return true if t is an anagram of s, and false otherwise.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase,
typically using all the original letters exactly once.



Example 1:

Input: s = "anagram", t = "nagaram"
Output: true
Example 2:

Input: s = "rat", t = "car"
Output: false


Constraints:

1 <= s.length, t.length <= 5 * 104
s and t consist of lowercase English letters.


Follow up: What if the inputs contain Unicode characters? How would you adapt your solution to such a case?


*/


using namespace std;

#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

namespace {

    class Solution {
    public:
        bool isAnagram(string s, string t) {
            if (s.length() != t.length())
                return false;

            unordered_map<char, int> charFreqMap;;
            for (int i = 0; i < s.length(); ++i) {
                charFreqMap[s[i]]++;
                charFreqMap[t[i]]--;
            }

            for (auto it : charFreqMap) {
                if (it.second != 0)
                    return false;
            }

            return true;
        }
    };

}