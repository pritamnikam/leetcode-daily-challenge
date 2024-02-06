// 49. Group Anagrams
// https://leetcode.com/problems/group-anagrams

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
