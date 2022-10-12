/*
976. Largest Perimeter Triangle
https://leetcode.com/problems/largest-perimeter-triangle/

Given an integer array nums, return the largest perimeter of a triangle with
a non-zero area, formed from three of these lengths. If it is impossible to
form any triangle of a non-zero area, return 0.

Example 1:
Input: nums = [2,1,2]
Output: 5

Example 2:
Input: nums = [1,2,1]
Output: 0


Constraints:
3 <= nums.length <= 104
1 <= nums[i] <= 106

*/

using namespace std;

#include <iostream>
#include <vector>
#include <algorithm>

namespace {
	class Solution {
	public:
		// a <= b <= c
		// a + b > c
		int largestPerimeter(vector<int>& nums) {
			if (nums.size()) return 0;

			sort(begin(nums), end(nums));
			for (int i = nums.size() - 3; i >= 0; --i) {
				if (nums[i] + nums[i + 1] > nums[i + 2]) {
					return nums[i] + nums[i + 1] + nums[i + 2];
				}
			}

			return 0;
		}
	};
}

void testLargestPerimeterTriangle() {
	vector<int> nums = { 2,1,2 };
	cout << "Largest Perimeter Triangle: " << Solution().largestPerimeter(nums) << endl;

	nums = { 1,2,1 };
	cout << "Largest Perimeter Triangle: " << Solution().largestPerimeter(nums) << endl;
}
