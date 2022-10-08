/*
16. 3Sum Closest
https://leetcode.com/problems/3sum-closest/

Given an integer array nums of length n and an integer target, find three integers in nums such that the sum is closest to target.

Return the sum of the three integers.

You may assume that each input would have exactly one solution.



Example 1:

Input: nums = [-1,2,1,-4], target = 1
Output: 2
Explanation: The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
Example 2:

Input: nums = [0,0,0], target = 1
Output: 0
Explanation: The sum that is closest to the target is 0. (0 + 0 + 0 = 0).


Constraints:

3 <= nums.length <= 1000
-1000 <= nums[i] <= 1000
-104 <= target <= 104

*/

using namespace std;

#include <vector>
#include <iostream>
#include <algorithm>

namespace {
	class Solution {
	public:
		int threeSumClosest(vector<int>& nums, int target) {
			// 1. sort the numbers and then apply twoSum
			sort(nums.begin(), nums.end());

			int result = INT_MAX;
			int minDifference = INT_MAX;

			// 2. for every elements - find a pair with sum diff is minimum
			for (int i = 0; i < nums.size(); ++i) {
				twoSum(nums, target, i, result, minDifference);
				if (minDifference == 0) break;
			}

			return result;
		}

	private:
		void twoSum(vector<int>& nums, 
					int target, 
					int index, 
					int& result, 
					int& minDifference) {
			int start = index + 1;
			int end = nums.size() - 1;

			while (start < end) {
				// calculate sum
				int currentSum = nums[index]
								+ nums[start]
								+ nums[end];

				if (target == currentSum) {
					result = target;
					minDifference = 0;
					return;
				}

				// update the result
				int diff = abs(currentSum - target);
				if (diff < minDifference) {
					minDifference = diff;
					result = currentSum;
				}

				// move pointers
				if (currentSum < target)
					++start;
				else
					--end;
			}
		}
	};
}
