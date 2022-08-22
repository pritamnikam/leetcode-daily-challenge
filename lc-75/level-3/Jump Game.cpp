/*
55. Jump Game
https://leetcode.com/problems/jump-game/

You are given an integer array nums. You are initially positioned at the array's first index, 
and each element in the array represents your maximum jump length at that position.

Return true if you can reach the last index, or false otherwise.

Example 1:
Input: nums = [2,3,1,1,4]
Output: true
Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.

Example 2:
Input: nums = [3,2,1,0,4]
Output: false
Explanation: You will always arrive at index 3 no matter what. Its maximum jump length is 0, which makes it impossible to reach the last index.


Constraints:

1 <= nums.length <= 104
0 <= nums[i] <= 105

*/
using namespace std;

#include <vector>
#include <iostream>

namespace {
    class Solution {
    public:
        enum State {
            UNKNOWN, BAD, GOOD
        };


        bool canJump(vector<int>& nums) {
            vector<State> dp(nums.size(), UNKNOWN);
            dp[nums.size() - 1] = GOOD;
            return canJump(nums, dp, 0);
        }


        bool canJump(vector<int>& nums, vector<State>& dp, int position) {
            if (dp[position] != UNKNOWN) {
                return dp[position] == GOOD;
            }

            size_t furthestPosition = min((int)(nums.size() - 1), 
                                          position + nums[position]);

            for (size_t newPosition = 1 + position;
                newPosition <= furthestPosition;
                ++newPosition) {
                if (canJump(nums, dp, newPosition)) {
                    dp[position] = GOOD;
                    return true;
                }
            }

            dp[position] = BAD;
            return false;
        }

        bool canJump2(vector<int>& nums) {
            int n = nums.size();
            vector<int> dp(n, UNKNOWN);

            // last positions:
            dp[n - 1] = GOOD;

            // Try remaining positions
            for (int i = n - 2; i >= 0; i--) {
                int furthestJump = min(i + nums[i], n - 1);
                for (int j = i + 1; j <= furthestJump; j++) {
                    if (dp[j] == GOOD) {
                        dp[i] = GOOD;
                        break;
                    }
                }
            }

            return dp[n - 1] == GOOD;
        }
    };

} // namespace

void testJumpGame() {
    vector<int> nums = { 2, 3, 1, 1, 4 };
    Solution().canJump(nums);
}