// 787. Cheapest Flights Within k Stops
// https://leetcode.com/problems/cheapest-flights-within-k-stops

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        // base case
        if (src == dst) {
            return 0;
        }

        vector<int> prev(n, INT_MAX);
        vector<int> cur(n, INT_MAX);

        prev[src] = cur[src] = 0;

        // perform k+1 iterations
        for (int i = 0; i <= k; i++) {
            for (auto f: flights) {
                int u = f[0], v = f[1], w = f[2];

                if (prev[u] < INT_MAX) {
                    cur[v] = min(cur[v], w + prev[u]);
                }
            }
            prev.assign(cur.begin(), cur.end());
        }

        return cur[dst] != INT_MAX ? cur[dst] : -1;
    }
};
