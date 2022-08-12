/*
815. Bus Routes
https://leetcode.com/problems/bus-routes/

You are given an array routes representing bus routes where routes[i]
is a bus route that the ith bus repeats forever.

For example, if routes[0] = [1, 5, 7], this means that the 0th bus travels
in the sequence 1 -> 5 -> 7 -> 1 -> 5 -> 7 -> 1 -> ... forever.

You will start at the bus stop source (You are not on any bus initially),
and you want to go to the bus stop target. You can travel between bus stops by buses only.

Return the least number of buses you must take to travel from source to target. 
Return -1 if it is not possible.



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
#include <string>
#include <vector>
#include <unordered_map>
#include <queue>
#include <unordered_set>

namespace {
	class BusRoutes {
	public:
		int numBusesToDestination(vector<vector<int>>& routes,
								  int source,
								  int target) {

			if (target == source) return 0;

			// {stop => {bus1, bus2, bus3, ...}}
			unordered_map<int, vector<int>> stopToBusesMap;
			for (int i = 0; i < routes.size(); ++i)
				for (int j : routes[i])
					stopToBusesMap[j].push_back(i);


			// BFS:
			// queue: {stop, bus}
			queue<pair<int, int>> queue;
			queue.push({ source, 0 });
			unordered_set<int> seen = { source };

			while (!queue.empty()) {
				auto current = queue.front();
				queue.pop();

				int stop = current.first, bus = current.second;

				// case 1: reached the destination
				if (stop == target)
					return bus;

				// neibhours: for all other buses to the stop
				for (int i: stopToBusesMap[stop]) {

					// all stops for the |i| bus.
					for (int j : routes[i]) {
						if (!seen.count(j)) {
							seen.insert(j);

							// {stop -> next bus}
							queue.push({ j, 1 + bus });
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

void testBusRoutes() {
	// routes = [[1, 2, 7], [3, 6, 7]], source = 1, target = 6
	vector<vector<int>> routes = { {1, 2, 7}, {3, 6, 7} };
	int source = 1, target = 6;

	cout << "Bus Routes: " << BusRoutes().numBusesToDestination(routes, source, target) << endl;
}