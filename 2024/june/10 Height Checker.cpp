// 1051. Height Checker
// https://leetcode.com/problems/height-checker

class Solution {
public:
    int heightChecker(vector<int>& heights) {
        map<int, int> countMap;
        for (int n: heights) {
            countMap[n]++;
        }

        int count = 0;
        int i = 0;
        for (auto it&: countMap) {
            for (int j = 0; j < it.second; j++) {
                if (heights[i] != it.first) {
                 ++count;   
                }
                ++i;
            }
        }

        return count;
    }
};
