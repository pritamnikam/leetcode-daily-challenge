/*
34. Find First and Last Position of Element in Sorted Array
https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/

Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.

If target is not found in the array, return [-1, -1].

You must write an algorithm with O(log n) runtime complexity.



Example 1:

Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]
Example 2:

Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]
Example 3:

Input: nums = [], target = 0
Output: [-1,-1]


Constraints:

0 <= nums.length <= 105
-109 <= nums[i] <= 109
nums is a non-decreasing array.
-109 <= target <= 109

*/


using namespace std;

#include <iostream>
#include <vector>


namespace {
	class Solution {
	public:
		vector<int> searchRange(vector<int>& nums, int target) {
			if (nums.empty() || target < nums[0] || target > nums[nums.size() - 1]) return { -1,-1 };

			vector<int> answer = { -1, -1 };
			answer[0] = findFirst(nums, target);
			if (answer[0] != -1)
				answer[1] = findLast(nums, target);
			return answer;
		}

	private:
		int findFirst(vector<int>& nums, int target) {
			int l = 0, r = nums.size() - 1, answer = -1;
			while (l <= r) {
				int mid = l + (r - l) / 2;
				if (nums[mid] == target) {
					answer = mid;
					r = mid - 1;
				}
				else if (nums[mid] > target) {
					r = mid - 1;
				}
				else {
					l = mid + 1;
				}
			}
			return answer;
		}

		int findLast(vector<int>& nums, int target) {
			int l = 0, r = nums.size() - 1, answer = -1;
			while (l <= r) {
				int mid = l + (r - l) / 2;
				if (nums[mid] == target) {
					answer = mid;
					l = mid + 1;
				}
				else if (nums[mid] > target) {
					r = mid - 1;
				}
				else {
					l = mid + 1;
				}
			}
			return answer;
		}
	};
}

void testFindFirstAndLast() {
	vector<int> nums = { 5, 7, 7, 8, 8, 10 };
	int target = 8;

	vector<int> answer = Solution().searchRange(nums, target);
}
