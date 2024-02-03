// 1043. Partition Array for Maximum Sum
// https://leetcode.com/problems/partition-array-for-maximum-sum

class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int N = arr.size();

        int dp[N + 1];
        memset(dp, 0, sizeof(dp));

        for (int start = N - 1; start >= 0; start--) {
            int curMax = 0;
            int end = min(N, start + k);

            for (int i = start; i < end; i++) {
                curMax = max(curMax, arr[i]);

                dp[start] = max(dp[start], 
                                dp[i + 1] + 
                                curMax * 
                                (i - start + 1));
            }
        }
        return dp[0];
    }
};
