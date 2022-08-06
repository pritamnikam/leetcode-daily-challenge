/*
1584. Min Cost to Connect All Points
https://leetcode.com/problems/min-cost-to-connect-all-points/

You are given an array points representing integer coordinates of some points on a 2D-plane, 
where points[i] = [xi, yi].

The cost of connecting two points [xi, yi] and [xj, yj] is the manhattan distance between 
them: |xi - xj| + |yi - yj|, where |val| denotes the absolute value of val.

Return the minimum cost to make all points connected. All points are connected if there is
exactly one simple path between any two points.

Input: points = [[0,0],[2,2],[3,10],[5,2],[7,0]]
Output: 20
Explanation:
We can connect the points as shown above to get the minimum cost of 20.
Notice that there is a unique path between every pair of points.

Input: points = [[3,12],[-2,5],[-4,1]]
Output: 18

Constraints:
1 <= points.length <= 1000
-106 <= xi, yi <= 106
All pairs (xi, yi) are distinct.


*/


using namespace std;

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <queue>

namespace {
    class Edge {
    public:
        int point1;
        int point2;
        int cost;
        Edge(int point1, int point2, int cost)
            : point1(point1), point2(point2), cost(cost) {}
    };
    // Overload the < operator.
    bool operator<(const Edge& edge1, const Edge& edge2) {
        return edge1.cost > edge2.cost;
    }

    class Solution {
    public:
        // Prim's algorithm
        int minCostConnectPoints(vector<vector<int>>& points) {
            if (points.size() == 0) {
                return 0;
            }

            int sz = points.size();
            vector<bool> visited(sz);
            priority_queue<Edge> pq;
            
            int result = 0;
            int count = sz - 1;

            // Add all edges from points[0] vertex
            vector<int>& coordinate1 = points[0];
            for (int j = 1; j < sz; j++) {
                // Calculate the distance between two coordinates
                vector<int>& coordinate2 = points[j];
                int cost = 
                    abs(coordinate1[0] - coordinate2[0]) + 
                    abs(coordinate1[1] - coordinate2[1]);
                Edge edge(0, j, cost);
                pq.push(edge);
            }

            visited[0] = true;

            // BFS:
            while (!pq.empty() && count > 0) {
                Edge edge = pq.top();
                pq.pop();

                int point1 = edge.point1;
                int point2 = edge.point2;
                int cost = edge.cost;

                if (!visited[point2]) {
                    result += cost;
                    visited[point2] = true;

                    // for all neighbours:
                    for (int j = 0; j < sz; j++) {
                        if (!visited[j]) {
                            int distance = 
                                abs(points[point2][0] - points[j][0]) +
                                abs(points[point2][1] - points[j][1]);

                            pq.push(Edge(point2, j, distance));
                        }
                    }
                    count--;
                }
            }
            return result;
        }
    };
}

void testMinCostToConnectAllPoints() {
/*
Input: points = [[0, 0], [2, 2], [3, 10], [5, 2], [7, 0]]
Output : 20
*/

    vector<vector<int>> points = {
        {0, 0}, {2, 2},
        {3, 10},{5, 2},
        {7, 0}
    };

    cout << "Min Cost to Connect All Points: " << Solution().minCostConnectPoints(points) << endl;
}
