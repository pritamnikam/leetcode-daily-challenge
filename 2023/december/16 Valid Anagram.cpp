// 242. Valid Anagram
// https://leetcode.com/problems/valid-anagram

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
        
        for (auto it: charFreqMap) {
            if (it.second != 0)
                return false;
        }
        
        return true;
    }
};
