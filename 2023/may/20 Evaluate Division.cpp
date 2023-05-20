/*
399. Evaluate Division
https://leetcode.com/problems/evaluate-division/

You are given an array of variable pairs equations and an array of real numbers values, where equations[i] = [Ai, Bi] and values[i] represent the equation Ai / Bi = values[i]. Each Ai or Bi is a string that represents a single variable.

You are also given some queries, where queries[j] = [Cj, Dj] represents the jth query where you must find the answer for Cj / Dj = ?.

Return the answers to all queries. If a single answer cannot be determined, return -1.0.

Note: The input is always valid. You may assume that evaluating the queries will not result in division by zero and that there is no contradiction.



Example 1:

Input: equations = [["a","b"],["b","c"]], values = [2.0,3.0], queries = [["a","c"],["b","a"],["a","e"],["a","a"],["x","x"]]
Output: [6.00000,0.50000,-1.00000,1.00000,-1.00000]
Explanation:
Given: a / b = 2.0, b / c = 3.0
queries are: a / c = ?, b / a = ?, a / e = ?, a / a = ?, x / x = ?
return: [6.0, 0.5, -1.0, 1.0, -1.0 ]
Example 2:

Input: equations = [["a","b"],["b","c"],["bc","cd"]], values = [1.5,2.5,5.0], queries = [["a","c"],["c","b"],["bc","cd"],["cd","bc"]]
Output: [3.75000,0.40000,5.00000,0.20000]
Example 3:

Input: equations = [["a","b"]], values = [0.5], queries = [["a","b"],["b","a"],["a","c"],["x","y"]]
Output: [0.50000,2.00000,-1.00000,-1.00000]


Constraints:

1 <= equations.length <= 20
equations[i].length == 2
1 <= Ai.length, Bi.length <= 5
values.length == equations.length
0.0 < values[i] <= 20.0
1 <= queries.length <= 20
queries[i].length == 2
1 <= Cj.length, Dj.length <= 5
Ai, Bi, Cj, Dj consist of lower case English letters and digits.


*/

using namespace std;

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>

namespace {
    class Solution {
    public:
        vector<double> calcEquation(vector<vector<string>>& equations,
            vector<double>& values,
            vector<vector<string>>& queries) {

            int size = equations.size();
            unordered_map<string, vector<pair<string, double>>> graph;

            // populate the graph
            for (int i = 0; i < size; ++i) {
                auto equation = equations[i];
                string src = equation[0];
                string dst = equation[1];
                double weight = values[i];

                graph[src].push_back({ dst, weight });
                graph[dst].push_back({ src, 1.0 / weight });
            }

            // perform DFS
            vector<double> result;
            for (auto query : queries) {
                string src = query[0];
                string dst = query[1];

                double answer = -1.0;
                unordered_set<string> visited;

                if (graph.count(src) && graph.count(dst))
                    dfs(graph, src, dst, visited, answer, 1.0);

                result.push_back(answer);
            }

            return result;
        }

    private:

        void dfs(unordered_map<string, vector<pair<string, double>>>& graph,
            string src,
            string dst,
            unordered_set<string>& visited,
            double& answer,
            double currentProduct) {

            // aleady visited
            if (visited.count(src)) {
                return;
            }

            // reached the destination
            if (src == dst) {
                answer = currentProduct;
                return;
            }

            // mark visited
            visited.insert(src);

            // adj list
            for (auto& entry : graph[src]) {
                dfs(graph,
                    entry.first,
                    dst,
                    visited,
                    answer,
                    currentProduct * entry.second);
            }
        }
    };
}
