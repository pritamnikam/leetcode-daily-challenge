/*
310. Minimum Height Trees
https://leetcode.com/problems/minimum-height-trees/

A tree is an undirected graph in which any two vertices are connected by exactly one path. 
In other words, any connected graph without simple cycles is a tree.

Given a tree of n nodes labelled from 0 to n - 1, and an array of n - 1 edges where edges[i] = [ai, bi] 
indicates that there is an undirected edge between the two nodes ai and bi in the tree, you can choose 
any node of the tree as the root. When you select a node x as the root, the result tree has height h. 

Among all possible rooted trees, those with minimum height (i.e. min(h))  are called minimum height trees (MHTs).

Return a list of all MHTs' root labels. You can return the answer in any order.

The height of a rooted tree is the number of edges on the longest downward path between the root and a leaf.


Input: n = 4, edges = [[1,0],[1,2],[1,3]]
Output: [1]
Explanation: As shown, the height of the tree is 1 when the root is the node with label 1 which is the only MHT.


Input: n = 6, edges = [[3,0],[3,1],[3,2],[3,4],[5,4]]
Output: [3,4]

Constraints:

1 <= n <= 2 * 104
edges.length == n - 1
0 <= ai, bi < n
ai != bi
All the pairs (ai, bi) are distinct.
The given input is guaranteed to be a tree and there will be no repeated edges.

*/

using namespace std;

#include <iostream>
#include <vector>
#include <unordered_map>
#include <deque>
#include <iterator>

namespace {
    class Solution {
    public:
        vector<int> findMinHeightTrees(int nodes, vector<vector<int>>& edges) {
            vector<int> minHeightTrees;
            if (nodes <= 0) {
                return minHeightTrees;
            }

            // with only one node, since its in-degree will be 0, therefore, we need to handle it separately
            if (nodes == 1) {
                minHeightTrees.push_back(0);
                return minHeightTrees;
            }

            // a. Initialize the graph
            unordered_map<int, int> inDegree;       // count of incoming edges for every vertex
            unordered_map<int, vector<int>> graph;  // adjacency list graph
            for (int i = 0; i < nodes; i++) {
                inDegree[i] = 0;
                graph[i] = vector<int>();
            }

            // b. Build the graph
            for (int i = 0; i < edges.size(); i++) {
                int n1 = edges[i][0], n2 = edges[i][1];
                // since this is an undirected graph, therefore, add a link for both the nodes
                graph[n1].push_back(n2);
                graph[n2].push_back(n1);
                // increment the in-degrees of both the nodes
                inDegree[n1]++;
                inDegree[n2]++;
            }

            // c. Find all leaves i.e., all nodes with only 1 in-degree
            deque<int> leaves;
            for (auto entry : inDegree) {
                if (entry.second == 1) {
                    leaves.push_back(entry.first);
                }
            }

            // d. Remove leaves level by level and subtract each leave's children's in-degrees.
            // Repeat this until we are left with 1 or 2 nodes, which will be our answer.
            // Any node that has already been a leaf cannot be the root of a minimum height tree, because
            // its adjacent non-leaf node will always be a better candidate.
            int totalNodes = nodes;
            while (totalNodes > 2) {
                int leavesSize = leaves.size();
                totalNodes -= leavesSize;
                for (int i = 0; i < leavesSize; i++) {
                    int vertex = leaves.front();
                    leaves.pop_front();
                    vector<int> children = graph[vertex];
                    for (auto child : children) {
                        inDegree[child]--;
                        if (inDegree[child] == 1) {  // if the child has become a leaf
                            leaves.push_back(child);
                        }
                    }
                }
            }

            std::move(std::begin(leaves), std::end(leaves), std::back_inserter(minHeightTrees));
            return minHeightTrees;
        }
    };
}  // namespace


void testFindMinHeightTrees() {
    // Input: n = 4, edges = [[1,0],[1,2],[1,3]]
    // Output: [1]
    
    int n = 4;
    vector<vector<int>> edges = { {1, 0},{1, 2},{1, 3} };
    vector<int> output = Solution().findMinHeightTrees(n, edges);
}
