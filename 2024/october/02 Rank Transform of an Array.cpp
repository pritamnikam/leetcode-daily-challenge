// 1331. Rank Transform of an Array
// https://leetcode.com/problems/rank-transform-of-an-array

class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        map<int, vector<int>> numToIndices;

        for (int i = 0; i < arr.size(); i++) {
            numToIndices[arr[i]].push_back(i);
        }

        int rank = 1;
        for (auto& pair: numToIndices) {
            for (int index: pair.second) {
                arr[index] = rank;
            }

            rank++;
        }

        return arr;
    }
};
