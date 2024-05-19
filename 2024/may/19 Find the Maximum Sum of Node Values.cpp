// 3068. Find the Maximum Sum of Node Values
// https://leetcode.com/problems/find-the-maximum-sum-of-node-values

using namespace std;

#include <iostream>
#include <vector>

namespace {
    class Solution {
    public:
        long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
            int n = nums.size();
            vector<vector<long long>> dp(n + 1, vector<long long>(2, 0));
            dp[n][1] = 0;
            dp[n][0] = INT_MIN;

            for (int index = n - 1; index >= 0; index--) {
                for (int isEven = 0; isEven <= 1; isEven++) {
                    long long performOp = dp[index + 1][isEven ^ 1] + (nums[index] ^ k);
                    long long dontPerformOp = dp[index + 1][isEven] + nums[index];

                    dp[index][isEven] = max(
                        performOp,
                        dontPerformOp
                    );
                }
            }
            return dp[0][1];
        }
    };
}