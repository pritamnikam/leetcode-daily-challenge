/*
16. 3Sum Closest
https://leetcode.com/problems/3sum-closest/

Given an integer array nums of length n and an integer target, find three integers in nums 
such that the sum is closest to target.

Return the sum of the three integers.

You may assume that each input would have exactly one solution.



Example 1:

Input: nums = [-1,2,1,-4], target = 1
Output: 2
Explanation: The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
Example 2:

Input: nums = [0,0,0], target = 1
Output: 0


Constraints:

3 <= nums.length <= 1000
-1000 <= nums[i] <= 1000
-104 <= target <= 104


*/


using namespace std;

#include <vector>
#include <iostream>
#include <unordered_map>
#include <algorithm>

namespace {

    class Solution {
        // 2 pointers - sorted array
        void twoSumClosest(vector<int>& nums,
            int target,
            int i,
            int& res,
            int& diff) {
            int n = nums.size();
            int low = i + 1;
            int high = n - 1;

            while (low < high) {
                int val = nums[i] + nums[low] + nums[high];
                if (val == target) {
                    res = val;
                    return;
                }

                // update answer
                if (abs(target - val) < diff) {
                    diff = abs(target - val);
                    res = val;
                }

                if (val < target) {
                    low++;
                }
                else {
                    high--;
                }
            }
        }

    public:
        int threeSumClosest1(vector<int>& nums, int target) {
            int res = 0;
            int diff = INT_MAX;
            int n = nums.size();

            // sorted array - 2 pointers
            sort(nums.begin(), nums.end());

            for (int i = 0; i < n - 2; i++) {
                twoSumClosest(nums, target, i, res, diff);
                if (res == target)
                    return target;
            }
            return res;
        }

        int threeSumClosest(vector<int>& nums, int target) {
            // 1. sort the numbers and then apply twoSum
            sort(nums.begin(), nums.end());

            int result = INT_MAX;
            int minDifference = INT_MAX;

            // for every elements - find a pair with sum diff is minimum
            for (int i = 0; i < nums.size() - 2; ++i) {
                twoSum(nums, target, i, result, minDifference);
                if (minDifference == 0)
                    break;
            }

            return result;
        }


        void twoSum(vector<int>& nums, int target, int i, int& result, int& minDifference) {
            int start = i + 1;
            int end = nums.size() - 1;

            while (start < end) {
                // calculate sum
                int currentSum = nums[i] + nums[start] + nums[end];
                if (currentSum == target) {
                    result = currentSum;
                    minDifference = 0;
                    return;
                }

                // update the result
                if (abs(currentSum - target) < minDifference) {
                    minDifference = abs(currentSum - target);
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