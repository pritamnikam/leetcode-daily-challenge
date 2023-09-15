// 1584. Min Cost to Connect All Points
// https://leetcode.com/problems/min-cost-to-connect-all-points/

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
