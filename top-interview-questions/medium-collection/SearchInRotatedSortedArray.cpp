/*
Search in Rotated Sorted Array

There is an integer array nums sorted in ascending order (with distinct values).

Prior to being passed to your function, nums is possibly rotated at an unknown pivot index k (1 <= k < nums.length) 
such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] 
(0-indexed). For example, [0,1,2,4,5,6,7] might be rotated at pivot index 3 and become [4,5,6,7,0,1,2].

Given the array nums after the possible rotation and an integer target, return the index of target if it is in 
nums, or -1 if it is not in nums.

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

#include <vector>

class Solution {

	int PivotIndex(vector<int>& arr) {
		int size = arr.size();
		int start = 0;
		int end = size - 1;

		while (start <= end) {
			int mid = start + (end - start) / 2;
			int prev = (mid + size - 1) % size;
			int next = (mid + 1) % size;

			if (arr[mid] <= arr[prev] && arr[mid] <= arr[next]) {
				return mid;
			}

			if (arr[mid] < arr[end]) {
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

	int BinarySearch(vector<int>& arr, int n, int start, int end) {
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
public:
	int search(vector<int>& nums, int target) {
		int pivot = PivotIndex(nums);
		int res = BinarySearch(nums, target, 0, pivot - 1);
		if (res == -1)
			res = BinarySearch(nums, target, pivot, nums.size() - 1);

		return res;
	}
};


class Solution {

	int BST(vector<int>& arr, int start, int end, int n) {
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

	int FindMinimumElement(vector<int>& arr, int size) {
		int start = 0;
		int end = size - 1;

		while (start <= end) {
			int mid = start + (end - start) / 2;
			int prev = (mid + size - 1) % size;
			int next = (mid + 1) % size;

			if (arr[mid] <= arr[prev] && arr[mid] <= arr[next]) {
				return mid;
			}

			if (arr[mid] < arr[end]) {
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

public:
	int search(vector<int>& nums, int target) {
		int size = nums.size();
		int pivot = FindMinimumElement(nums, size);
		int res = BST(nums, 0, pivot - 1, target);
		if (res == -1)
			res = BST(nums, pivot, size - 1, target);

		return res;
	}
};