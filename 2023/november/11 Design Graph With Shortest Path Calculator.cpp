// 2642. Design Graph With Shortest Path Calculator.cpp
// https://leetcode.com/problems/design-graph-with-shortest-path-calculator


using namespace std;

#include <iostream>
#include <vector>

namespace {
class Graph {
    vector<vector<int>> matrix;

public:
    Graph(int n, vector<vector<int>>& edges) {
        matrix = vector<vector<int>>(n, vector<int>(n, 1e9));

        // {u, v, w}
        for (auto& edge: edges) {
            matrix[edge[0]][edge[1]] = edge[2];
        }

        for (int i = 0; i < n; i++) {
            matrix[i][i] = 0;
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < n; k++) {
                    matrix[j][k] = min(matrix[j][k], matrix[j][i] + matrix[i][k]);
                }
            }
        }
    }
    
    void addEdge(vector<int> edge) {
        int n = matrix.size();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                matrix[i][j] = min(matrix[i][j],
                                    matrix[i][edge[0]] +
                                    matrix[edge[1]][j] +
                                    edge[2]);
            }
        }
    }
    
    int shortestPath(int node1, int node2) {
        if (matrix[node1][node2] == 1e9) return -1;
        return matrix[node1][node2];
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */
}
