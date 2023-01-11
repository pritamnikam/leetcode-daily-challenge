/*
1443. Minimum Time to Collect All Apples in a Tree
https://leetcode.com/problems/minimum-time-to-collect-all-apples-in-a-tree/

Given an undirected tree consisting of n vertices numbered from 0 to n-1, which has some 
apples in their vertices. You spend 1 second to walk over one edge of the tree. Return the 
minimum time in seconds you have to spend to collect all apples in the tree, starting at 
vertex 0 and coming back to this vertex.

The edges of the undirected tree are given in the array edges, where edges[i] = [ai, bi] means
that exists an edge connecting the vertices ai and bi. Additionally, there is a boolean array 
hasApple, where hasApple[i] = true means that vertex i has an apple; otherwise, it does not have
any apple.

Example 1:
Input: n = 7, edges = [[0,1],[0,2],[1,4],[1,5],[2,3],[2,6]], hasApple = [false,false,true,false,true,true,false]
Output: 8
Explanation: The figure above represents the given tree where red vertices have an apple. One optimal path to collect all apples is shown by the green arrows.

Example 2:
Input: n = 7, edges = [[0,1],[0,2],[1,4],[1,5],[2,3],[2,6]], hasApple = [false,false,true,false,false,true,false]
Output: 6
Explanation: The figure above represents the given tree where red vertices have an apple. One optimal path to collect all apples is shown by the green arrows.

Example 3:
Input: n = 7, edges = [[0,1],[0,2],[1,4],[1,5],[2,3],[2,6]], hasApple = [false,false,false,false,false,false,false]
Output: 0


Constraints:
1 <= n <= 105
edges.length == n - 1
edges[i].length == 2
0 <= ai < bi <= n - 1
fromi < toi
hasApple.length == n

*/

using namespace std;

#include <iostream>
#include <vector>

namespace {
    class Solution {
    public:
        int minTime(int n, 
                    vector<vector<int>>& edges, 
                    vector<bool>& hasApple) {

            vector<vector<int>> adj(n);
            for (auto& edge : edges) {
                adj[edge[0]].push_back(edge[1]);
                adj[edge[1]].push_back(edge[0]);
            }

            return dfs(0, -1, adj, hasApple);
        }

    private:
        int dfs(int node, 
                int parent, 
                vector<vector<int>>& adj, 
                vector<bool>& hasApple) {

            int totalTime = 0, 
                childTime = 0;

            for (auto child : adj[node]) {
                // cycle: don't proceed
                if (child == parent) continue;

                // get the time for every child
                childTime = dfs(child, node, adj, hasApple);

                if (childTime || hasApple[child]) totalTime += childTime + 2;
            }

            return totalTime;
        }
    };
} // namespace 


void testMinimumTimeToCollectAllApplesInTree() {
    /*
        Example 1: 
        Input: n = 7,
        edges = [[0,1],[0,2],[1,4],[1,5],[2,3],[2,6]], 
        hasApple = [false,false,true,false,true,true,false]
        
        Output: 8
    */

    int n = 7;
    vector<vector<int>> edges = { {0, 1},{0, 2},{1, 4},{1, 5},{2, 3},{2, 6} };
    vector<bool> hasApple = { false, false, true, false, true, true, false };
    cout << "Minimum Time to Collect All Apples in a Tree: "
        << Solution().minTime(n, edges, hasApple) << endl;
}
