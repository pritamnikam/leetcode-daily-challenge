// 452. Minimum Number of Arrows to Burst Balloons
// https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if (points.empty()) return 0;

        // sort intervals
        sort(
            points.begin(),
            points.end(),
            [](auto const&vt1, auto const& vt2) { return vt1[1] < vt2[1]; }
        );

        // need atleast a arrow
        int answer = 1, 
            arrowPosition = points[0][1];

        for (int i = 1; i < points.size(); i++) {
            // need new arrow
            if (arrowPosition < points[i][0]) {
                arrowPosition = points[i][1];
                answer++;
            }
        }

        return answer;
    }
};
