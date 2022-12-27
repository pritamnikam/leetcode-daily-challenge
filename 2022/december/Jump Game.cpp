/*
55. Jump Game
https://leetcode.com/problems/jump-game/description/

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
#include <algorithm>

namespace {
	enum class State {
		UNKNOWN, BAD, GOOD
	};

	class Solution {
	public:
		
		// Bottom-up DP:
		bool canJump(vector<int>& nums) {
			int n = nums.size();
			vector<State> dp(n, State::UNKNOWN);

			// last location:
			dp[n - 1] = State::GOOD;

			// Try remaining positions
			for (int i = n - 2; i >= 0; i--) {
				int furthestJump = min(i + nums[i], n - 1);
				for (int j = i + 1; j <= furthestJump; j++) {
					if (dp[j] == State::GOOD) {
						dp[i] = State::GOOD;
						break;
					}
				}
			}

			return dp[0] == State::GOOD;
		}

		// recurrsion
		bool canJumpRecurrsion(vector<int>& nums) {
			vector<State> dp(nums.size(), State::UNKNOWN);
			dp[nums.size() - 1] = State::GOOD;
			return canJump(nums, dp, 0);
		}

	private:
		bool canJump(vector<int>& nums, vector<State>& dp, size_t position) {
			if (dp[position] != State::UNKNOWN) {
				return dp[position] == State::GOOD;
			}

			size_t furthestPosition = min(nums.size() - 1, position + nums[position]);
			for (size_t newPosition = 1 + position;
				newPosition <= furthestPosition;
				++newPosition) {
				if (canJump(nums, dp, newPosition)) {
					dp[position] = State::GOOD;
					return true;
				}
			}

			dp[position] = State::BAD;
			return false;
		}
	};

} // namespace
