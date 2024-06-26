// 310. Minimum Height Tree
// https://leetcode.com/problems/minimum-height-trees

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
