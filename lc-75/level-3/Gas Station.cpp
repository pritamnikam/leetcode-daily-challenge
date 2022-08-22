/*
134. Gas Station
https://leetcode.com/problems/gas-station/

There are n gas stations along a circular route, where the amount of gas at the ith station is gas[i].

You have a car with an unlimited gas tank and it costs cost[i] of gas to travel from the ith station to its next (i + 1)th station. You begin the journey with an empty tank at one of the gas stations.

Given two integer arrays gas and cost, return the starting gas station's index if you can travel around the circuit once in the clockwise direction, otherwise return -1. If there exists a solution, it is guaranteed to be unique



Example 1:

Input: gas = [1,2,3,4,5], cost = [3,4,5,1,2]
Output: 3
Explanation:
Start at station 3 (index 3) and fill up with 4 unit of gas. Your tank = 0 + 4 = 4
Travel to station 4. Your tank = 4 - 1 + 5 = 8
Travel to station 0. Your tank = 8 - 2 + 1 = 7
Travel to station 1. Your tank = 7 - 3 + 2 = 6
Travel to station 2. Your tank = 6 - 4 + 3 = 5
Travel to station 3. The cost is 5. Your gas is just enough to travel back to station 3.
Therefore, return 3 as the starting index.
Example 2:

Input: gas = [2,3,4], cost = [3,4,3]
Output: -1
Explanation:
You can't start at station 0 or 1, as there is not enough gas to travel to the next station.
Let's start at station 2 and fill up with 4 unit of gas. Your tank = 0 + 4 = 4
Travel to station 0. Your tank = 4 - 3 + 2 = 3
Travel to station 1. Your tank = 3 - 3 + 3 = 3
You cannot travel back to station 2, as it requires 4 unit of gas but you only have 3.
Therefore, you can't travel around the circuit once no matter where you start.


Constraints:

n == gas.length == cost.length
1 <= n <= 105
0 <= gas[i], cost[i] <= 104

*/

#include <iostream>
#include <vector>

using namespace std;

/*
Intution:
	The first idea is to check every single station:
		- Choose the station as starting point.
		- Perform the road trip and check how much gas we have in tank at each station.

Observations:
	- It's impossible to start at a station i if gas[i] - cost[i] < 0, because then there is not enough gas in the tank to travel to i + 1 station. In this situation the answer is -1.

*/

namespace {
	class Solution {
	public:
		int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
			int n = gas.size();

			int total_surplus = 0,
				surplus = 0,
				start = 0;

			// for all stations as starting point:
			for (int i = 0; i < n; i++) {
				total_surplus += (gas[i] - cost[i]);
				surplus += (gas[i] - cost[i]);

				// if we cannot start from |start| go to next station
				if (surplus < 0) {
					surplus = 0;
					start+=i;
				}
			}

			return total_surplus >= 0 ? start : -1;
		}
	};
}  // namespace


void testGasStation() {
	vector<int> gas = { 1, 2, 3, 4, 5 },
		cost = { 3, 4, 5, 1, 2 };

	cout << "Gas Station: " << Solution().canCompleteCircuit(gas, cost) << endl;
}