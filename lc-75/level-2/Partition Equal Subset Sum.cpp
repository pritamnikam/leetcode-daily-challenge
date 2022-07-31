/*
416. Partition Equal Subset Sum
https://leetcode.com/problems/partition-equal-subset-sum/

Given a non-empty array nums containing only positive integers, find if the array can be partitioned 
into two subsets such that the sum of elements in both subsets is equal.

Example 1:

Input: nums = [1,5,11,5]
Output: true
Explanation: The array can be partitioned as [1, 5, 5] and [11].

Example 2:
Input: nums = [1,2,3,5]
Output: false
Explanation: The array cannot be partitioned into equal sum subsets.


Constraints:

1 <= nums.length <= 200
1 <= nums[i] <= 100

*/


using namespace std;

#include <iostream>
#include <vector>

namespace {
    class Solution {
public:
    bool canPartition(vector<int>& nums) {
        if (nums.empty()) return false;


        int sum = 0;
        for (int n : nums) sum += n;
        if (sum % 2) return false;

        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(sum / 2 + 1, -1));
        return canPartition(nums, sum / 2, 0, dp);
    }


    bool canPartition(vector<int>& nums,
                      int sum,
                      int currentIndex,
                      vector<vector<int>>& dp) {
        // base check
        if (sum == 0) {
            return true;
        }

        if (nums.empty() || currentIndex >= nums.size()) {
            return false;
        }


        // if we have not already processed a similar problem
        if (dp[currentIndex][sum] == -1) {
            // recursive call after choosing the number at the currentIndex
            // if the number at currentIndex exceeds the sum, we shouldn't process this
            if (nums[currentIndex] <= sum) {
                if (canPartition(nums,
                                 sum - nums[currentIndex],
                                 currentIndex + 1,
                                 dp)) {
                    dp[currentIndex][sum] = 1;
                    return true;
                }
            }

            // recursive call after excluding the number at the currentIndex
            dp[currentIndex][sum] = canPartition(nums,
                                                 sum,
                                                 currentIndex + 1,
                                                 dp) ? 1 : 0;
        }

        return dp[currentIndex][sum] == 1;
    }


     bool canPartitionDP(vector<int>& nums) {
        if (nums.empty()) return false;


        int sum = 0;
        for (int n : nums) sum += n;
        if (sum % 2) return false;

        sum = sum / 2;
        int n = nums.size();
        vector<vector<bool>> dp(n, vector<bool>(sum + 1));

        for (int i = 0; i < n; ++i) dp[i][0] = true;
        for (int s = 1; s <= sum; ++s) dp[0][s] = (s == nums[0]);

         for (int i = 1; i < n; ++i) {
             for (int s = 1; s <= sum; ++s) {
                 dp[i][s] = dp[i - 1][s];
                 if (s >= nums[i])
                     dp[i][s] = dp[i - 1][s - nums[i]];
             }
         }

         return dp[n - 1][sum];
    }
};
}