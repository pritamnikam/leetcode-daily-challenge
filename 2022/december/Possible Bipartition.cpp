/*
886. Possible Bipartition
https://leetcode.com/problems/possible-bipartition/

We want to split a group of n people (labeled from 1 to n) into two groups of any size. Each person may dislike
some other people, and they should not go into the same group.

Given the integer n and the array dislikes where dislikes[i] = [ai, bi] indicates that the person labeled ai 
does not like the person labeled bi, return true if it is possible to split everyone into two groups in this way.

Example 1:
Input: n = 4, dislikes = [[1,2],[1,3],[2,4]]
Output: true
Explanation: group1 [1,4] and group2 [2,3].

Example 2:
Input: n = 3, dislikes = [[1,2],[1,3],[2,3]]
Output: false

Example 3:
Input: n = 5, dislikes = [[1,2],[2,3],[3,4],[4,5],[1,5]]
Output: false

Constraints:
1 <= n <= 2000
0 <= dislikes.length <= 104
dislikes[i].length == 2
1 <= dislikes[i][j] <= n
ai < bi
All the pairs of dislikes are unique.
*/

using namespace std;

#include <iostream>
#include <vector>

namespace {

    class UnionFind {
    private:
        vector<int> parent, rank;

    public:
        UnionFind(int size) {
            parent.resize(size);
            rank.resize(size, 0);

            for (int i = 0; i < size; i++) {
                parent[i] = i;
            }
        }

        int find(int x) {
            if (parent[x] != x) parent[x] = find(parent[x]);
            return parent[x];
        }

        void union_set(int x, int y) {
            int xset = find(x), 
                yset = find(y);

            if (xset == yset) {
                return;
            }

            else if (rank[xset] < rank[yset]) {
                parent[xset] = yset;
            }
            else if (rank[xset] > rank[yset]) {
                parent[yset] = xset;
            }
            else {
                parent[yset] = xset;
                rank[xset]++;
            }
        }
    };

    class Solution {
    public:
        bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
            // adjustancy list
            vector<vector<int>> adj(n + 1);
            for (auto& dislike : dislikes) {
                adj[dislike[0]].push_back(dislike[1]);
                adj[dislike[1]].push_back(dislike[0]);
            }

            UnionFind dsu(n + 1);
            for (int node = 1; node <= n; node++) {
                for (int neighbor : adj[node]) {
                    // Check if the node and its neighbor is in the same set.
                    if (dsu.find(node) == dsu.find(neighbor)) return false;

                    // Move all the neighbours into same set as the first neighbour.
                    dsu.union_set(adj[node][0], neighbor);
                }
            }
            return true;
        }
    };

}  // namespace

void testPossibleBipartition() {
/*

    Example 1:
    Input: n = 4, dislikes = [[1,2],[1,3],[2,4]]
    Output: true
    Explanation: group1 [1,4] and group2 [2,3].

    Example 2:
    Input: n = 3, dislikes = [[1,2],[1,3],[2,3]]
    Output: false

    Example 3:
    Input: n = 5, dislikes = [[1,2],[2,3],[3,4],[4,5],[1,5]]
    Output: false
*/
    int n = 4;
    vector<vector<int>> dislikes = {
        {1,2},{1,3},{2,4 }
    };

    cout << "Possible Bipartition: " << Solution().possibleBipartition(n, dislikes) << endl;

    n = 3;
    dislikes = {
        {1,2} ,{1,3},{2,3}
    };

    cout << "Possible Bipartition: " << Solution().possibleBipartition(n, dislikes) << endl;

    n = 5;
    dislikes = {
        {1,2},{2,3},{3,4},{4,5},{1,5}
    };

    cout << "Possible Bipartition: " << Solution().possibleBipartition(n, dislikes) << endl;

}
