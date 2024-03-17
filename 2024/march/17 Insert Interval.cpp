// 57. Insert Interval
// https://leetcode.com/problems/insert-interval/

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        if (intervals.empty()) {
            return vector<vector<int>>{newInterval};
        }
        
        vector<vector<int>> result;
        // we have intervals in sorted order
        // we can solve this problem in 3 steps.
        // 1. add all non-overlapping intervals
        int i = 0;
        int n = intervals.size();
        
        // intervals[i].end < newInterval.start
        while (i < n and intervals[i][1] < newInterval[0]) {
            result.push_back(intervals[i]);
            ++i;
            
        }
        
        // 2. merge all overlapping intervals
        // intervals[i].start <= newInterval.end
        while (i < n and intervals[i][0] <= newInterval[1]) {
            newInterval[0] = min(intervals[i][0], newInterval[0]); 
            newInterval[1] = max(intervals[i][1], newInterval[1]);
            ++i;
        }
        result.push_back(newInterval);
        
        
        // 3. remaining intervals
        while (i < n) {
            result.push_back(intervals[i]);
            ++i;
        } 
        
        return result;
    }
};
