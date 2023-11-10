// 1743. Restore the Array from Adjacent Pairs
// https://leetcode.com/problems/restore-the-array-from-adjacent-pairs

using namespace std;

#include <iostream>
#include <vector>
#include <unordered_map>

class Solution {
    unordered_map<int, vector<int>> graph;

    void dfs(int node, int prev, vector<int>& ans) {
        ans.push_back(node);
        for (int neighbor : graph[node]) {
            if (neighbor != prev) {
                dfs(neighbor, node, ans);
            }
        }
    }

public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        for (auto& edge: adjacentPairs) {
            graph[edge[0]].emplace_back(edge[1]);
            graph[edge[1]].emplace_back(edge[0]);
        }

        int root = 0;
        for (auto& pair: graph) {
            if (pair.second.size() == 1) {
                root = pair.first;
                break;
            }
        }

        vector<int> ans;
        dfs(root, INT_MAX, ans);
        return ans;
    }
};
