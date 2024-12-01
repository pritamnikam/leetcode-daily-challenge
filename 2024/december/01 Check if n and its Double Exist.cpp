// Check if n and its Double Exist
// https://leetcode.com/problems/check-if-n-and-its-double-exist/

class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_map<int, int> freqMap;
        for (int n: arr) {
            freqMap[n]++;
        }

        for (int n: arr) {
            if (n != 0 && freqMap.find(2 * n) != freqMap.end()) {
                return true;
            }

            if (n == 0 && freqMap[n] > 1) {
                return true;
            }
        }
        return false;
    }
};
