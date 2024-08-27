// 1514. Path wih Maximum Probability
// https://leetcode.com/problems/path-with-maximum-probability/


class Solution {
public:
    double maxProbability(
        int n, 
        vector<vector<int>>& edges, 
        vector<double>& succProb, 
        int start, 
        int end
    ) {
        vector<double> maxProb = vector<double>(n, 0);
        maxProb[start] = 1.0;

        // Bellmon-Ford Shortest Path
        for (int i = 0; i < n - 1; i++) {
            bool hasUpdated = false;

            // Relax all edges
            for (int j = 0; j < edges.size(); j++) {
                int u = edges[j][0],
                    v = edges[j][1];
                double pathProb = succProb[j];

                if (maxProb[u] * pathProb > maxProb[v]) {
                    maxProb[v] = maxProb[u] * pathProb;
                    hasUpdated = true;
                }
                if (maxProb[v] * pathProb > maxProb[u]) {
                    maxProb[u] = maxProb[v] * pathProb;
                    hasUpdated = true;
                }
            }

            if (!hasUpdated) {
                break;
            }
        }

        return maxProb[end];
    }
};
