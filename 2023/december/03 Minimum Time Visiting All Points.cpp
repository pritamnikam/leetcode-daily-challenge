// 1266. Minimum Time Visiting All Points
// https://leetcode.com/problems/minimum-time-visiting-all-points/description/

class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int answer = 0;
        for (int i = 0; i < points.size() - 1; i++) {
            int currX = points[i][0];
            int currY = points[i][1];

            int targetX = points[i + 1][0];
            int targetY = points[i + 1][1];

            answer += max(abs(targetX-currX), abs(targetY-currY));
        }
        return answer;
    }
};
