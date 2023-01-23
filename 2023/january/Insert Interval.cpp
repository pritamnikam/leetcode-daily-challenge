/*
57. Insert Interval
https://leetcode.com/problems/insert-interval/

You are given an array of non-overlapping intervals intervals where intervals[i] = [starti, endi] represent the start and the end of the ith interval and intervals is sorted in ascending order by starti. You are also given an interval newInterval = [start, end] that represents the start and end of another interval.

Insert newInterval into intervals such that intervals is still sorted in ascending order by starti and intervals still does not have any overlapping intervals (merge overlapping intervals if necessary).

Return intervals after the insertion.



Example 1:

Input: intervals = [[1,3],[6,9]], newInterval = [2,5]
Output: [[1,5],[6,9]]
Example 2:

Input: intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
Output: [[1,2],[3,10],[12,16]]
Explanation: Because the new interval [4,8] overlaps with [3,5],[6,7],[8,10].


Constraints:

0 <= intervals.length <= 104
intervals[i].length == 2
0 <= starti <= endi <= 105
intervals is sorted by starti in ascending order.
newInterval.length == 2
0 <= start <= end <= 105

*/
using namespace std;

#include <iostream>
#include <vector>
#include <algorithm>

namespace {
    class Solution {
    public:
        vector<vector<int>> insert(
            vector<vector<int>>& intervals,
            vector<int>& newInterval) {

            // base case:
            if (intervals.empty()) {
                return { newInterval };
            }

            // sort intervals by start time
            sort(intervals.begin(), intervals.end());

            // all intervals before |newInterval|.
            int i = 0, 
                n = intervals.size();

            vector<vector<int>> result;
            while (i < n
                && intervals[i][1] < newInterval[0]) {
                result.push_back(intervals[i]);
                ++i;
            }

            // all intervals overlappig with |newInterval|.
            while (i < n
                && intervals[i][0] <= newInterval[1]) {
                newInterval[0] = min(newInterval[0], intervals[i][0]);
                newInterval[1] = max(newInterval[1], intervals[i][1]);
                ++i;
            }

            result.push_back(newInterval);

            // all intervals after |newInterval|.
            while (i < n) {
                result.push_back(intervals[i]);
                ++i;
            }

            return result;
        }
    };
}  // namespace

void testInsertInterval() {
    // Input: intervals = [[1,3],[6,9]], newInterval = [2,5], Output: [[1, 5], [6, 9]]
    vector<vector<int>> intervals = { {1, 3},{6, 9} };
    vector<int> newInterval = { 2, 5 };

    vector<vector<int>> result = Solution().insert(intervals, newInterval);
}