// 1578. Minimum Time to Make Rope Colorful
// https://leetcode.com/problems/minimum-time-to-make-rope-colorful

class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int n = colors.size();
        vector<int> dp(n, -1);
        return recurrsion(n - 1, colors, neededTime, dp, 'A', neededTime[n - 1]);
    }

    int recurrsion(
        int i,
        string& colors,
        vector<int>& neededTime,
        vector<int>& dp,
        char previousColor,
        int previousTime

    ) {
        // base case: reached the beginning of the sequence
        if (i < 0) {
            return 0;
        }

        if (dp[i] != -1) {
            // if the sub-problem is solved earlier, return the stored resulr
            return dp[i];
        }

        if (colors[i] == previousColor) {
            // If the current color is the same as the previous one, choose the minimum time
            return dp[i] = recurrsion(i - 1, colors, neededTime, dp, colors[i], max(neededTime[i], previousTime)) + min(neededTime[i], previousTime);
        } else {
            // If the current color is different, choose the time required for the current color
            return dp[i] = recurrsion(i - 1, colors, neededTime, dp, colors[i], neededTime[i]);
        }
    }
};
