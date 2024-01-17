// 1207. Unique Number of Occurances
// https://leetcode.com/problems/unique-number-of-occurrences/

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> counts;
        for (int n: arr) {
            counts[n]++;
        }

        set<int> uniques;
        for (auto& it: counts) {
            uniques.insert(it.second);
        }

        return uniques.size()==counts.size();
    }
};
