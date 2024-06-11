// 1122. Relative Sort Array
// https://leetcode.com/problems/relative-sort-array/

class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        map<int, int> freqMap;
        for (int n: arr1) {
            freqMap[n]++;
        }

        vector<int> result;
        for (int n: arr2) {
            int m = freqMap[n];
            for (int i = 0; i < m; i++) {
                result.push_back(n);
                freqMap[n]--;
                if (freqMap[n] == 0) {
                    freqMap.erase(n);
                }
            }
        }

        for (auto& it: freqMap) {
            int n = it.first;
            int m = it.second;
            for (int i = 0; i < m; i++) {
                result.push_back(n);
            }
        }

        return result;
    }
};
