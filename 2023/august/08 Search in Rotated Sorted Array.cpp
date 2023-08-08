/*
33. Search in Rotated Sorted Array
https://leetcode.com/problems/search-in-rotated-sorted-array

There is an integer array nums sorted in ascending order (with distinct values).

Prior to being passed to your function, nums is possibly rotated at an unknown pivot index k (1 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,5,6,7] might be rotated at pivot index 3 and become [4,5,6,7,0,1,2].

Given the array nums after the possible rotation and an integer target, return the index of target if it is in nums, or -1 if it is not in nums.

You must write an algorithm with O(log n) runtime complexity.



Example 1:

Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4
Example 2:

Input: nums = [4,5,6,7,0,1,2], target = 3
Output: -1
Example 3:

Input: nums = [1], target = 0
Output: -1


Constraints:

1 <= nums.length <= 5000
-104 <= nums[i] <= 104
All values of nums are unique.
nums is an ascending array that is possibly rotated.
-104 <= target <= 104

*/

using namespace std;

#include <iostream>
#include <vector>

namespace {
	class Solution {
	public:
		int search(vector<int>& nums, int target) {
			int pivot = findPivot(nums);
			int res = binarySearch(nums, target, 0, pivot - 1);
			if (res == -1) {
				res = binarySearch(nums, target, pivot, nums.size() - 1);
			}
			return res;
		}

	private:
		int findPivot(vector<int>& nums) {
			int size = nums.size();
			int start = 0;
			int end = size - 1;

			while (start <= end) {
				int mid = start + (end - start) / 2;
				int prev = (mid + size - 1) % size;
				int next = (mid + 1) % size;

				if (nums[mid] <= nums[prev] && nums[mid] <= nums[next]) {
					return mid;
				}

				if (nums[mid] < nums[end]) {
					// right array is sorted
					end = mid - 1;
				}
				else {
					// left array is sorted.
					start = 1 + mid;
				}
			}

			return 0;
		}

		int binarySearch(vector<int>& arr, int n, int start, int end) {
			while (start <= end) {
				int mid = start + (end - start) / 2;
				if (arr[mid] == n)
					return mid;

				if (arr[mid] < n) {
					start = mid + 1;
				}
				else {
					end = mid - 1;
				}
			}

			return -1;
		}
	};
} // namespace
