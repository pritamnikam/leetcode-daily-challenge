/*
90. Subsets II
https://leetcode.com/problems/subsets-ii/

Given an integer array nums that may contain duplicates, return all possible subsets (the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.



Example 1:

Input: nums = [1,2,2]
Output: [[],[1],[1,2],[1,2,2],[2],[2,2]]
Example 2:

Input: nums = [0]
Output: [[],[0]]


Constraints:

1 <= nums.length <= 10
-10 <= nums[i] <= 10

*/


using namespace std;

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

namespace {
	class Solution {
	public:
		vector<vector<int>> subsetsWithDup(vector<int>& nums) {
			set<vector<int>> s;
			int n = nums.size();

			for (int i = 0; i < (1 << n); i++) {
				vector<int> temp;
				for (int bit = 0; bit < n; bit++) {
					if (1 & (i >> bit)) {
						temp.push_back(nums[bit]);
					}
				}

				sort(temp.begin(), temp.end());
				s.insert(temp);
			}
			vector<vector<int>> ans(s.begin(), s.end());
			return ans;
		}
	};
} // namespace


void testSubsetsWithDup() {
	vector<int> nums = { 1, 2, 2 };
	vector<vector<int>> subset = Solution().subsetsWithDup(nums);
}