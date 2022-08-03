/*
Merge Intervals

Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, 
and return an array of the non-overlapping intervals that cover all the intervals in the input.

Example 1:

Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].
Example 2:

Input: intervals = [[1,4],[4,5]]
Output: [[1,5]]
Explanation: Intervals [1,4] and [4,5] are considered overlapping.


Constraints:

1 <= intervals.length <= 104
intervals[i].length == 2
0 <= starti <= endi <= 104

*/

using namespace std;

#include <string>
#include <vector>
#include <algorithm>

class Solution {
public:
	vector<vector<int>> merge(vector<vector<int>>& intervals) {
		// sort all intervals O(n log n)
		sort(intervals.begin(), intervals.end(),
			[](const vector<int>& a, const vector<int>& b) {
				return a[0] < b[0];
			});

		vector<vector<int>> result;
		for (auto interval : intervals) {
			// if the list of merged intervals is empty or if the current
			// interval does not overlap with the previous, simply append it.
			if (result.empty() || interval[0] > result.back()[1]) {
				result.push_back(interval);
			}
			else {
				// otherwise, there is overlap, so we merge the current and previous
				// intervals.
				result.back()[1] = max(result.back()[1], interval[1]);
			}
		}

		return result;
	}
};