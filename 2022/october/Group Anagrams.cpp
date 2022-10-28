/*
49. Group Anagrams
https://leetcode.com/problems/group-anagrams/

Given an array of strings strs, group the anagrams together. You can return the answer in any order.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

 

Example 1:
Input: strs = ["eat","tea","tan","ate","nat","bat"]
Output: [["bat"],["nat","tan"],["ate","eat","tea"]]

Example 2:
Input: strs = [""]
Output: [[""]]

Example 3:
Input: strs = ["a"]
Output: [["a"]] 

Constraints:
1 <= strs.length <= 104
0 <= strs[i].length <= 100
strs[i] consists of lowercase English letters.

*/

using namespace std;

#include <string>
#include <vector>
#include <unordered_map>

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        if (strs.empty()) return result;

        const int kSize = 26;
        unordered_map<string, vector<string>> stringToSetMap;
        for (string str : strs) {
            
            vector<int> charFreqMap(kSize, 0);
            for (char ch: str) charFreqMap[ch - 'a']++;

            string key;
            for (int i = 0; i < kSize; ++i) {
                key += "#";
                key += to_string(charFreqMap[i]);
            }

            stringToSetMap[key].emplace_back(str);
        }

        for (auto it : stringToSetMap)
            result.emplace_back(it.second.begin(), it.second.end());

        return result;  
    }
};
