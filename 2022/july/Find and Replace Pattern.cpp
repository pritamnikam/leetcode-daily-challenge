/*
890. Find and Replace Pattern
https://leetcode.com/problems/find-and-replace-pattern/

Given a list of strings words and a string pattern, return a list of words[i] that match pattern. 
You may return the answer in any order.

A word matches the pattern if there exists a permutation of letters p so that after replacing every
letter x in the pattern with p(x), we get the desired word.

Recall that a permutation of letters is a bijection from letters to letters: every letter maps to 
another letter, and no two letters map to the same letter.



Example 1:

Input: words = ["abc","deq","mee","aqq","dkd","ccc"], pattern = "abb"
Output: ["mee","aqq"]
Explanation: "mee" matches the pattern because there is a permutation {a -> m, b -> e, ...}.
"ccc" does not match the pattern because {a -> c, b -> c, ...} is not a permutation, since a and b map 
to the same letter.

Example 2:
Input: words = ["a","b","c"], pattern = "a"
Output: ["a","b","c"]


Constraints:
1 <= pattern.length <= 20
1 <= words.length <= 50
words[i].length == pattern.length
pattern and words[i] are lowercase English letters.

*/


using namespace std;

#include <iostream>
#include <vector>
#include <unordered_map>

namespace {
    class Solution {
    public:
        vector<string> findAndReplacePattern(vector<string>& words,
            string pattern) {
            vector<string> answer;
            for (string& word : words) {
                if (match(word, pattern)) {
                    answer.push_back(word);
                }
            }

            return answer;
        }

        bool match(string& word, string& pattern) {
            unordered_map<char, char> m1, m2;

            for (int i = 0; i < word.length(); ++i) {
                char w = word[i],
                     p = pattern[i];

                if (!m1.count(w)) m1[w] = p;
                if (!m2.count(p)) m2[p] = w;

                if (m1[w] != p || m2[p] != w) return false;
            }

            return true;
        }
    };
}  // namespace