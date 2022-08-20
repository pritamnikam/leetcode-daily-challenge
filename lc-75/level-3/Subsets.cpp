/*
78. Subsets
https://leetcode.com/problems/subsets/

Given an integer array nums of unique elements, return all possible subsets (the power set).
The solution set must not contain duplicate subsets. Return the solution in any order.

Example 1:
Input: nums = [1,2,3]
Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]

Example 2:
Input: nums = [0]
Output: [[],[0]]

Constraints:
1 <= nums.length <= 10
-10 <= nums[i] <= 10
All the numbers of nums are unique.

*/



using namespace std;

#include <iostream>
#include <vector>

namespace {
	class Solution {
	public:
		vector<vector<int>> subsets(vector<int>& nums) {
			if (nums.size() <= 1)
				return { nums };

			vector<vector<int>> result;
			vector<int> currentSet;

			subsets(nums, result, currentSet, 0);
			return result;
		}

	private:
		void subsets(vector<int>& nums, 
					vector<vector<int>> result,
					vector<int> currentSet,
					int current) {

			// base case:
			if (current == nums.size()) {
				result.push_back(currentSet);
				return;
			}

			currentSet.push_back(nums[current]);
			subsets(nums, result, currentSet, 1 + current);

			currentSet.pop_back();
			subsets(nums, result, currentSet, 1 + current);
		}
	};
}

void testSubsets() {
	vector<int> nums = { 1, 2, 3 };

	vector<vector<int>> result = Solution().subsets(nums);
}