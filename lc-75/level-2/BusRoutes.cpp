/*
815. Bus Routes
https://leetcode.com/problems/bus-routes/

You are given an array routes representing bus routes where routes[i] is a bus route that the ith bus repeats forever.

For example, if routes[0] = [1, 5, 7], this means that the 0th bus travels in the sequence 1 -> 5 -> 7 -> 1 -> 5 -> 7 -> 1 -> ... forever.
You will start at the bus stop source (You are not on any bus initially), and you want to go to the bus stop target. You can travel between bus stops by buses only.

Return the least number of buses you must take to travel from source to target. Return -1 if it is not possible.



Example 1:

Input: routes = [[1,2,7],[3,6,7]], source = 1, target = 6
Output: 2
Explanation: The best strategy is take the first bus to the bus stop 7, then take the second bus to the bus stop 6.
Example 2:

Input: routes = [[7,12],[4,5,15],[6],[15,19],[9,12,13]], source = 15, target = 12
Output: -1


Constraints:

1 <= routes.length <= 500.
1 <= routes[i].length <= 105
All the values of routes[i] are unique.
sum(routes[i].length) <= 105
0 <= routes[i][j] < 106
0 <= source, target < 106
*/

using namespace std;


#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <unordered_set>

namespace {
    class Solution {
    public:
        int numBusesToDestination(vector<vector<int>>& routes,
            int source,
            int target) {
            // 1. Build tree: {stop -> bus1, bus2, bus3, ....}
            unordered_map<int, vector<int>> to_routes;
            for (int i = 0; i < routes.size(); ++i)
                for (int j : routes[i])
                    to_routes[j].push_back(i);

            // 2. preform BFS
            // queue: {stop, bus}
            queue<pair<int, int>> bfs;
            bfs.push({ source, 0 });

            unordered_set<int> seen = { source };

            while (!bfs.empty()) {
                auto current = bfs.front();  bfs.pop();

                int stop = current.first,
                    bus = current.second;

                // reached the destination
                if (stop == target)
                    return bus;

                // for all busses to the |stop|
                for (int i : to_routes[stop]) {

                    // all stops for the |i| bus.
                    for (int j : routes[i]) {

                        // if stop is not seen
                        if (seen.find(j) == seen.end()) {
                            seen.insert(j);

                            // {stop -> next bus}
                            bfs.push({ j, bus + 1 });
                        }
                    }

                    // clear the |i| bus's route
                    routes[i].clear();
                }
            }

            return -1;
        }
    };
}
