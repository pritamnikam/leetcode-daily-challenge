/*
2492. Minimum Score of a Path Between Two Cities
https://leetcode.com/problems/minimum-score-of-a-path-between-two-cities/

You are given a positive integer n representing n cities numbered from 1 to n. You are also given a 2D array roads where roads[i] = [ai, bi, distancei] indicates that there is a bidirectional road between cities ai and bi with a distance equal to distancei. The cities graph is not necessarily connected.

The score of a path between two cities is defined as the minimum distance of a road in this path.

Return the minimum possible score of a path between cities 1 and n.

Note:

A path is a sequence of roads between two cities.
It is allowed for a path to contain the same road multiple times, and you can visit cities 1 and n multiple times along the path.
The test cases are generated such that there is at least one path between 1 and n.


Example 1:


Input: n = 4, roads = [[1,2,9],[2,3,6],[2,4,5],[1,4,7]]
Output: 5
Explanation: The path from city 1 to 4 with the minimum score is: 1 -> 2 -> 4. The score of this path is min(9,5) = 5.
It can be shown that no other path has less score.
Example 2:


Input: n = 4, roads = [[1,2,2],[1,3,4],[3,4,7]]
Output: 2
Explanation: The path from city 1 to 4 with the minimum score is: 1 -> 2 -> 1 -> 3 -> 4. The score of this path is min(2,2,4,7) = 2.


Constraints:

2 <= n <= 105
1 <= roads.length <= 105
roads[i].length == 3
1 <= ai, bi <= n
ai != bi
1 <= distancei <= 104
There are no repeated edges.
There is at least one path between 1 and n.

*/

using namespace std;

#include <iostream>
#include <vector>


namespace {
    class DisjointSet {
    public:
        vector<int> parent, size;
        DisjointSet(int n) {
            parent.resize(n + 1);
            size.resize(n + 1);
            for (int i = 1; i <= n; i++) {
                parent[i] = i;
                size[i] = 1;
            }
        }

        int findUlt(int node) {
            if (node == parent[node]) return node;
            return parent[node] = findUlt(parent[node]);
        }

        void findUnion(int u, int v) {
            int paru = findUlt(u);
            int parv = findUlt(v);
            if (paru == parv) return;
            if (size[paru] > size[parv]) {
                parent[parv] = paru;
                size[paru]++;
            }
            else if (size[paru] > size[parv]) {
                parent[paru] = parv;
                size[parv]++;
            }
            else {
                parent[parv] = paru;
                size[paru]++;
            }
        }
    };


    class Solution {
    public:
        int minScore(int n, vector<vector<int>>& roads) {
            DisjointSet ds(n);
            for (auto it : roads) {
                ds.findUnion(it[0], it[1]);
            }

            int temp = ds.findUlt(1), 
                ans = INT_MAX;

            for (auto it : roads) {
                int ult_u = ds.findUlt(it[0]), 
                    ult_v = ds.findUlt(it[1]);

                if (ult_u == temp || ult_v == temp)
                    ans = min(ans, it[2]);
            }
            return ans;
        }
    };
}

void testMinimumScoreBetweenTwoCities() {
    /*
        Input: n = 4, roads = [[1,2,9],[2,3,6],[2,4,5],[1,4,7]]
        Output: 5
    */
    int n = 4;
    vector<vector<int>> roads = { {1, 2, 9},{2, 3, 6},{2, 4, 5},{1, 4, 7} };
    cout << "Minimum Score of a Path Between Two Cities: " << Solution().minScore(n, roads) << endl;
}
