/*
377. Combination Sum IV
https://leetcode.com/problems/combination-sum-iv/

Given an array of distinct integers nums and a target integer target, 
return the number of possible combinations that add up to target.

The test cases are generated so that the answer can fit in a 32-bit integer.

Example 1:

Input: nums = [1,2,3], target = 4
Output: 7
Explanation:
The possible combination ways are:
(1, 1, 1, 1)
(1, 1, 2)
(1, 2, 1)
(1, 3)
(2, 1, 1)
(2, 2)
(3, 1)
Note that different sequences are counted as different combinations.
Example 2:

Input: nums = [9], target = 3
Output: 0


Constraints:
1 <= nums.length <= 200
1 <= nums[i] <= 1000
All the elements of nums are unique.
1 <= target <= 1000


Follow up: What if negative numbers are allowed in the given array? 
How does it change the problem? What limitation we need to add to the 
question to allow negative numbers?


*/

using namespace std;

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

namespace {
	class Solution {
	public:
		int combinationSum4(vector<int>& nums, int target) {
			sort(nums.begin(), nums.end());
			return combinationSumMemo(nums, target);
		}


	private:
		unordered_map<int, int> memo;

		int combinationSumMemo(vector<int>& nums, int target) {
			// reached the target
			if (target == 0) {
				return 1;
			}

			// we already know the answer
			if (memo.count(target)) {
				return memo[target];
			}

			int result = 0;

			// for every number try calculating the sum
			for (int n : nums) {
				if (target >= n) {
					result += combinationSumMemo(nums, target - n);
				}
				else {
					break;
				}
			}
			memo[target] = result;
			return result;
		}
	};
}  // namesapce

void testCombinationSumIV() {
	vector<int> nums = { 1, 2, 3 };
	int target = 4;

	cout << "Combination Sum IV: " << Solution().combinationSum4(nums, target) << endl;
}
