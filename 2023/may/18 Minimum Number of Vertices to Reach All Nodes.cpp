/*
1557. Minimum Number of Vertices to Reach All Nodes
https://leetcode.com/problems/minimum-number-of-vertices-to-reach-all-nodes/

Given a directed acyclic graph, with n vertices numbered from 0 to n-1, and an array edges where edges[i] = [fromi, toi] represents a directed edge from node fromi to node toi.

Find the smallest set of vertices from which all nodes in the graph are reachable. It's guaranteed that a unique solution exists.

Notice that you can return the vertices in any order.

Given a directed acyclic graph, with n vertices numbered from 0 to n-1, and an array edges where edges[i] = [fromi, toi] represents a directed edge from node fromi to node toi.

Find the smallest set of vertices from which all nodes in the graph are reachable. It's guaranteed that a unique solution exists.

Notice that you can return the vertices in any order.

Example 1:
Input: n = 6, edges = [[0,1],[0,2],[2,5],[3,4],[4,2]]
Output: [0,3]
Explanation: It's not possible to reach all the nodes from a single vertex. From 0 we can reach [0,1,2,5]. From 3 we can reach [3,4,2,5]. So we output [0,3].

Example 2:
Input: n = 5, edges = [[0,1],[2,1],[3,1],[1,4],[2,4]]
Output: [0,2,3]
Explanation: Notice that vertices 0, 3 and 2 are not reachable from any other node, so we must include them. Also any of these vertices can reach nodes 1 and 4.

Constraints:
2 <= n <= 10^5
1 <= edges.length <= min(10^5, n * (n - 1) / 2)
edges[i].length == 2
0 <= fromi, toi < n
All pairs (fromi, toi) are distinct.

[Algorithm]
1. Create a boolean list isIncomingEdgeExists of length NNN which store true if there is an incoming edge to it, false otherwise. Initialize it with every entry as false.
2. Iterate over edges, and for every edge, mark the second vertex as true in the list isIncomingEdgeExists.
3. Iterate over the list isIncomingEdgeExists and include all the vertices that have a false value in the final answer list requiredNodes.
4. Return requiredNodes.
*/

using namespace std;

#include <iostream>
#include <vector>

namespace {

    class Solution {
    public:
        vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
            // List to signify if the vertex has an incoming edge or not.
            vector<bool> isIncomingEdgeExists(n, false);
            for (vector<int>& edge : edges) {
                isIncomingEdgeExists[edge[1]] = true;
            }

            vector<int> requiredNodes;
            for (int i = 0; i < n; i++) {
                // Store all the nodes that don't have an incoming edge.
                if (!isIncomingEdgeExists[i]) {
                    requiredNodes.push_back(i);
                }
            }

            return requiredNodes;
        }
    };

}  // namespace
