/*
739. Daily Temperatures
https://leetcode.com/problems/daily-temperatures/

Given an array of integers temperatures represents the daily temperatures, return an array 
answer such that answer[i] is the number of days you have to wait after the ith day to get 
a warmer temperature. If there is no future day for which this is possible, keep answer[i] == 0 instead.

Example 1:
Input: temperatures = [73,74,75,71,69,72,76,73]
Output: [1,1,4,2,1,1,0,0]

Example 2:
Input: temperatures = [30,40,50,60]
Output: [1,1,1,0]

Example 3:
Input: temperatures = [30,60,90]
Output: [1,1,0]

Constraints:
1 <= temperatures.length <= 105
30 <= temperatures[i] <= 100


*/

using namespace std;

#include <iostream>
#include <vector>
#include <stack>

namespace {
	class Solution {
	public:
		// Next bigger element (NGR)
		vector<int> dailyTemperatures(vector<int>& temperatures) {
			stack<pair<int, int>> st;
			vector<int> vt;
			int n = temperatures.size();

            for (int i = n - 1; i >= 0; --i) {
                if (st.empty()) vt.push_back(0);

                else if (st.top().first > temperatures[i]) {
                    vt.push_back(st.top().second - i);
                }

                else {
                    while (!st.empty() &&
                        st.top().first <= temperatures[i]) {
                        st.pop();
                    }

                    if (st.empty()) {
                        vt.push_back(0);
                    }
                    else if (st.top().first > temperatures[i]) {
                        vt.push_back(st.top().second - i);
                    }
                }

                st.push({ temperatures[i], i });
            }

            reverse(vt.begin(), vt.end());
            return vt;

		}
	};

}  // namespace

void testDailyTemperatures() {
    // Input: temperatures = [73,74,75,71,69,72,76,73], Output: [1, 1, 4, 2, 1, 1, 0, 0]

    vector<int> temperatures = { 73, 74, 75, 71, 69, 72, 76, 73 };
    vector<int> result = Solution().dailyTemperatures(temperatures);
}
