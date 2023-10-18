// Parallel Courses III
// https://leetcode.com/problems/parallel-courses-iii/

using namespace std;

#include <iostream>
#include <vector>
#include <unordered_map>


namespace {
class Solution {
    unordered_map<int, vector<int>> graph;
    vector<int> memo;
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        for (auto& edge: relations) {
            int x = edge[0] - 1, y = edge[1] - 1;
            graph[x].push_back(y);
        }

        memo = vector(n, -1);
        int ans = 0;

        for (int node = 0; node < n; node++) {
            ans = max(ans, dfs(node, time));
        }
        return ans;
    }

private:
    int dfs(int node, vector<int>& time) {
        if (memo[node] != -1) return memo[node];
        if (graph[node].size() == 0) return time[node];
        int ans = 0;
        for (int neibhor: graph[node]) {
            ans = max(ans, dfs(neibhor, time));
        }

        memo[node] = time[node] + ans;
        return memo[node];
    }
};
}
