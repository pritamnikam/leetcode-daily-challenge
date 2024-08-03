// 1460. Make Two Arrays Equal by Reversing Subarrays
// https://leetcode.com/problems/make-two-arrays-equal-by-reversing-subarrays/

class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        unordered_map<int, int> freqMap;
        for (int n: arr) {
            freqMap[n]++;
        }

        for (int n: target) {
            if (freqMap.find(n) == freqMap.end()) {
                return false;
            }

            freqMap[n]--;
            if (freqMap[n] == 0) {
                freqMap.erase(n);
            }
        }

        return freqMap.size() == 0;
    }
};
