/*
767. Reorganize String
https://leetcode.com/problems/reorganize-string/

Given a string s, rearrange the characters of s so that any two adjacent characters are not the same.

Return any possible rearrangement of s or return "" if not possible.

 

Example 1:

Input: s = "aab"
Output: "aba"
Example 2:

Input: s = "aaab"
Output: ""
 

Constraints:

1 <= s.length <= 500
s consists of lowercase English letters.

*/
using namespace std;

#include <iostream>
#include <vector>
#include <queue>
#include <string>

namespace {
class Solution {
public:
    string reorganizeString(string s) {
        vector<int> charCount(26, 0);
        for (char ch: s) {
            charCount[ch - 'a']++;
        }

        priority_queue<vector<int>> maxHeap;
        for (int i = 0; i < 26; i++) {
            if (charCount[i]) {
                maxHeap.push({charCount[i], i + 'a'});
            }
        }

        string result;
        while (!maxHeap.empty()) {
            auto first = maxHeap.top();
            maxHeap.pop();

            if (result.empty() || first[1] != result.back()) {
                result += char(first[1]);
                if (--first[0] > 0) {
                    maxHeap.push(first);
                }
            } else {
                if (maxHeap.empty()) {
                    return "";
                }
                auto second = maxHeap.top();
                maxHeap.pop();
                result += char(second[1]);
                if (--second[0] > 0) {
                    maxHeap.push(second);
                }
                maxHeap.push(first);
            }
        }

        return result;
    }
};

}
