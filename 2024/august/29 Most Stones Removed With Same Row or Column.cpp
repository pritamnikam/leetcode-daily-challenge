// 947. Most Stones Removed With Same Row or Column
// https://leetcode.com/problems/most-stones-removed-with-same-row-or-column

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        
        int numOfIslands = 0;
        vector<vector<int>> graph(stones.size());
        unordered_set<int> seen;

        // build graph
        for (int i = 0; i < stones.size(); ++i) {
            for (int j = i + 1; j < stones.size(); ++j) {
                // If are in same rows or columns
                if (stones[i][0] == stones[j][0] || 
                    stones[i][1] == stones[j][1]) {
                    graph[i].push_back(j);
                    graph[j].push_back(i);
                }
            }
        }

        // DFS on all location of stones
        for (int i = 0; i < stones.size(); ++i) {
            if (!seen.count(i)) {
                dfs(graph, i, seen);
                ++numOfIslands;
            }
        }

        return stones.size() - numOfIslands;
    }

    void dfs(const vector<vector < int>>& graph, 
        int u, unordered_set< int >& seen) {
        seen.insert(u);
        for (const int v: graph[u])
            if (seen.find(v) == seen.end())
                dfs(graph, v, seen);
    }
};
