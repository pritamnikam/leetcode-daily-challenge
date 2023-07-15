/*
1751. Maximum Number of Events That Can Be Attended II
https://leetcode.com/problems/maximum-number-of-events-that-can-be-attended-ii/description/

You are given an array of events where events[i] = [startDayi, endDayi, valuei]. The ith event starts at startDayi and ends at endDayi, and if you attend this event, you will receive a value of valuei. You are also given an integer k which represents the maximum number of events you can attend.

You can only attend one event at a time. If you choose to attend an event, you must attend the entire event. Note that the end day is inclusive: that is, you cannot attend two events where one of them starts and the other ends on the same day.

Return the maximum sum of values that you can receive by attending events.



Example 1:



Input: events = [[1,2,4],[3,4,3],[2,3,1]], k = 2
Output: 7
Explanation: Choose the green events, 0 and 1 (0-indexed) for a total value of 4 + 3 = 7.
Example 2:



Input: events = [[1,2,4],[3,4,3],[2,3,10]], k = 2
Output: 10
Explanation: Choose event 2 for a total value of 10.
Notice that you cannot attend any other event as they overlap, and that you do not have to attend k events.
Example 3:



Input: events = [[1,1,1],[2,2,2],[3,3,3],[4,4,4]], k = 3
Output: 9
Explanation: Although the events do not overlap, you can only attend 3 events. Pick the highest valued three.


Constraints:

1 <= k <= events.length
1 <= k * events.length <= 106
1 <= startDayi <= endDayi <= 109
1 <= valuei <= 106

*/

using namespace std;

#include <vector>
#include <iostream>
#include <algorithm>

namespace {
    class Solution {
    public:
        vector<vector<int>>dp;
        //dp[n][k+1]
        int maxValue(vector<vector<int>>& events, int k) {
            sort(events.begin(), events.end());
            int n = events.size();
            dp.resize(n, vector<int>(k + 1, -1));
            return solve(events, 0, k, 0);
        }
        int solve(vector<vector<int>>& events, int i, int k, int end) {
            if (i == events.size()) return 0;

            if (k == 0) return 0;

            if (events[i][0] <= end) return solve(events, i + 1, k, end);

            if (dp[i][k] != -1) return dp[i][k];

            int choices = max(events[i][2] + solve(events, i + 1, k - 1, events[i][1]), solve(events, i + 1, k, end));
            return dp[i][k] = choices;
        }
    };
}
