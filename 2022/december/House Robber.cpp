/*
198. House Robber
https://leetcode.com/problems/house-robber/

You are a professional robber planning to rob houses along a street. 
Each house has a certain amount of money stashed, the only constraint 
stopping you from robbing each of them is that adjacent houses have 
security systems connected and it will automatically contact the police 
if two adjacent houses were broken into on the same night.

Given an integer array nums representing the amount of money of each house, 
return the maximum amount of money you can rob tonight without alerting the police.

Example 1:
Input: nums = [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
Total amount you can rob = 1 + 3 = 4.

Example 2:
Input: nums = [2,7,9,3,1]
Output: 12
Explanation: Rob house 1 (money = 2), rob house 3 (money = 9) and rob house 5 (money = 1).
Total amount you can rob = 2 + 9 + 1 = 12.

Constraints:
1 <= nums.length <= 100
0 <= nums[i] <= 400

*/

using namespace std;

#include <iostream>
#include <vector>
#include <unordered_map>

namespace {
    class Solution {
    public:
        // Optimized Dynamic Programming
        int rob(vector<int>& nums) {
            int include = 0, 
                exclude = 0;

            for (int num : nums) {
                int newInclude = exclude + num;
                exclude = max(exclude, include);
                include = newInclude;
            }

            return max(exclude, include);
        }


        // recurrsion with memo
        unordered_map<int, int> cache;

        int rob1(vector<int>& nums) {
            if (nums.empty()) return 0;
            return rob(nums, 0);
        }

        int rob(vector<int>& nums, int currentHouse) {
            // already cached results:
            if (cache.count(currentHouse)) {
                return cache[currentHouse];
            }

            // base case:
            if (currentHouse >= nums.size()) {
                return 0;
            }

            int amountRobbingCurrentHouse = rob(nums, 2 + currentHouse) + nums[currentHouse];
            int amountNotRobbingCurrentHouse = rob(nums, 1 + currentHouse);

            cache[currentHouse] = max(amountRobbingCurrentHouse, amountNotRobbingCurrentHouse);
            return cache[currentHouse];
        }


        // DP
        int rob2(vector<int>& nums) {
            int n = nums.size();
            // Special handling for empty array case.
            if (n == 0) {
                return 0;
            }

            vector<int> dp(n + 1);

            // Base case initializations.
            dp[n] = 0;
            dp[n - 1] = nums[n - 1];

            // DP table calculations.
            for (int i = n - 2; i >= 0; --i) {
                // Same as the recursive solution.
                dp[i] = max(dp[i + 1], nums[i] + dp[i + 2]);
            }

            return dp[0];
        }
    };
} // namespace

void testHouseRobber() {
    // Input: nums = [1,2,3,1], Output: 4
    vector<int>  nums = { 1, 2, 3, 1 };
    cout << "House Robber: " << Solution().rob(nums) << endl;
}
