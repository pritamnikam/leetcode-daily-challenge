// 2406. Divide Intervals into Minimum Number of Groups
// https://leetcode.com/problems/divide-intervals-into-minimum-number-of-groups/
class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        int rangeStart = INT_MAX;
        int rangeEnd = INT_MIN;

        for (auto& it: intervals) {
            rangeStart = min(rangeStart, it[0]);
            rangeEnd = max(rangeEnd, it[1]);
        }

        vector<int> pointToCoun(rangeEnd + 2, 0);
        for (auto& it: intervals) {
            pointToCoun[it[0]]++;
            pointToCoun[it[1] + 1]--;
        }

        int concurrentIntervals = 0;
        int maxConcurrentIntervals = 0;
        for (int i = rangeStart; i <= rangeEnd; i++) {
            concurrentIntervals += pointToCoun[i];
            maxConcurrentIntervals = max(maxConcurrentIntervals, concurrentIntervals);
        }

        return maxConcurrentIntervals;
    }


};
