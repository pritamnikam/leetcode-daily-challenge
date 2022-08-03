/*
Search for a Range

Given an array of integers nums sorted in non-decreasing order, 
find the starting and ending position of a given target value.

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

#include <string>
#include <vector>

class Solution {
    int FindFirst(vector<int>& nums, int target) {
        int answer = -1;
        int start = 0, end = nums.size() - 1;
        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (nums[mid] == target) {
                answer = mid;
                end = mid - 1;
            }
            else if (nums[mid] < target) {
                start = mid + 1;
            }
            else {
                end = mid - 1;
            }
        }

        return answer;
    }

    int FindLast(vector<int>& nums, int target) {
        int answer = -1;
        int start = 0, end = nums.size() - 1;
        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (nums[mid] == target) {
                answer = mid;
                start = mid + 1;
            }
            else if (nums[mid] < target) {
                start = mid + 1;
            }
            else {
                end = mid - 1;
            }
        }

        return answer;
    }


public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> result = { -1, -1 };
        result[0] = FindFirst(nums, target);
        if (result[0] != -1)
            result[1] = FindLast(nums, target);
        return result;
    }
};

class Solution {
    int searchRangeFirst(vector<int>& nums, int target, int start, int end) {
        int result = -1;
        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (nums[mid] == target) {
                result = mid;
                end = mid - 1;
            }
            else if (nums[mid] < target) {
                start = mid + 1;
            }
            else {
                end = mid - 1;
            }
        }

        return result;
    }

    int searchRangeLast(vector<int>& nums, int target, int start, int end) {
        int result = -1;
        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (nums[mid] == target) {
                result = mid;
                start = mid + 1;
            }
            else if (nums[mid] < target) {

                start = mid + 1;
            }
            else {
                end = mid - 1;
            }
        }

        return result;
    }

public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> result;
        int first = searchRangeFirst(nums, target, 0, nums.size() - 1);
        int last = searchRangeLast(nums, target, 0, nums.size() - 1);
        result.push_back(first);
        result.push_back(last);
        return result;
    }
};