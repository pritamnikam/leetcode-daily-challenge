/*
1697. Checking Existence of Edge Length Limited Paths
https://leetcode.com/problems/checking-existence-of-edge-length-limited-paths/

An undirected graph of n nodes is defined by edgeList, where edgeList[i] = [ui, vi, disi] denotes an edge between nodes ui and vi with distance disi. Note that there may be multiple edges between two nodes.

Given an array queries, where queries[j] = [pj, qj, limitj], your task is to determine for each queries[j] whether there is a path between pj and qj such that each edge on the path has a distance strictly less than limitj .

Return a boolean array answer, where answer.length == queries.length and the jth value of answer is true if there is a path for queries[j] is true, and false otherwise.



Example 1:


Input: n = 3, edgeList = [[0,1,2],[1,2,4],[2,0,8],[1,0,16]], queries = [[0,1,2],[0,2,5]]
Output: [false,true]
Explanation: The above figure shows the given graph. Note that there are two overlapping edges between 0 and 1 with distances 2 and 16.
For the first query, between 0 and 1 there is no path where each distance is less than 2, thus we return false for this query.
For the second query, there is a path (0 -> 1 -> 2) of two edges with distances less than 5, thus we return true for this query.
Example 2:


Input: n = 5, edgeList = [[0,1,10],[1,2,5],[2,3,9],[3,4,13]], queries = [[0,4,14],[1,4,13]]
Output: [true,false]
Exaplanation: The above figure shows the given graph.


Constraints:

2 <= n <= 105
1 <= edgeList.length, queries.length <= 105
edgeList[i].length == 3
queries[j].length == 3
0 <= ui, vi, pj, qj <= n - 1
ui != vi
pj != qj
1 <= disi, limitj <= 109
There may be multiple edges between two nodes.


*/

using namespace std;

#include <iostream>
#include <vector>
#include <algorithm>

namespace {
    class DSU {
    public:
        vector<int> Parent, Rank;

        DSU(int n) {
            Parent.resize(n);
            Rank.resize(n, 0);
            for (int i = 0; i < n; i++) Parent[i] = i;
        }

        int Find(int x) {
            return Parent[x] = Parent[x] == x ? x : Find(Parent[x]);
        }

        bool Union(int x, int y) {
            int xset = Find(x), yset = Find(y);
            if (xset != yset) {
                Rank[xset] < Rank[yset] ? Parent[xset] = yset : Parent[yset] = xset;
                Rank[xset] += Rank[xset] == Rank[yset];
                return true;
            }
            return false;
        }
    };


    class Solution {
    public:
        vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {
            DSU dsu(n);
            for (int i = 0; i < queries.size(); i++) {
                queries[i].push_back(i);
            }

            sort(queries.begin(), queries.end(), [&](auto const& a, auto const& b) {
                return a[2] < b[2];
                });

            sort(edgeList.begin(), edgeList.end(), [&](auto const& a, auto const& b) {
                return a[2] < b[2];
                });


            int i = 0;
            vector<bool> res(queries.size(), false);
            for (auto q : queries) {
                while (i < edgeList.size() && edgeList[i][2] < q[2]) {
                    dsu.Union(edgeList[i][0], edgeList[i][1]);
                    i++;
                }

                if (dsu.Find(q[0]) == dsu.Find(q[1]))
                    res[q[3]] = true;
            }

            return res;
        }
    };

    class Solution2 {
    public:
        vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {
            vector<vector<pair<int, int>>> adj(n);
            for (auto e : edgeList) {
                int u = e[0], v = e[1], w = e[2];
                adj[u].push_back({ v, w });
                adj[v].push_back({ u, w });
            }

            vector<bool> ans;
            for (auto q : queries) {
                int source = q[0], target = q[1], limit = q[2];
                ans.push_back(pathExists(adj, source, target, limit));
            }
            return ans;

        }
    private:
        const int INF = 1e9;

        bool pathExists(
            vector<vector<pair<int, int>>>& adj,
            int source, int target, int limit) {
            priority_queue<
                pair<int, int>,
                vector<pair<int, int>>,
                greater<pair<int, int>>> pq;

            pq.push({ 0, source });
            unordered_map<int, int> dist;
            dist[source] = 0;

            while (!pq.empty()) {
                int u = pq.top().second;
                int d = pq.top().first;
                pq.pop();
                if (u == target && d < limit) {
                    return true;
                }
                if (dist[u] < d) {
                    continue;
                }
                for (auto v : adj[u]) {
                    int w = v.second;
                    int newDist = dist[u] + w;
                    if (newDist < limit
                        && (!dist.count(v.first)
                            || newDist < dist[v.first])) {
                        dist[v.first] = newDist;
                        pq.push({ newDist, v.first });
                    }
                }
            }
            return false;
        }

    };
}
