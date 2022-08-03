/*
3Sum

Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

Notice that the solution set must not contain duplicate triplets.

Example 1:
Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]

Example 2:
Input: nums = []
Output: []

Example 3:
Input: nums = [0]
Output: []

Constraints:
0 <= nums.length <= 3000
-105 <= nums[i] <= 105

*/

class Solution {
    void twoSum(vector<int>& nums, int i, int j, int k, vector<vector<int>>& ans) {
        int n = nums.size();
        while (j < n && j < k) {
            if (nums[j] + nums[k] == -nums[i]) {
                // answer
                ans.push_back({ nums[i],
                               nums[j],
                               nums[k] });

                // to avoid duplicates
                while (k != 0 && nums[k] == nums[k - 1]) k--;
                while (j != n - 1 && nums[j] == nums[j + 1]) j++;

                // advace pointers
                j++, k--;
            }
            // move right pointer
            else if (nums[j] + nums[k] > -nums[i]) {
                // to avoid duplicates
                while (k != 0 && nums[k] == nums[k - 1]) k--;
                k--;
            }
            // move left pointer
            else {
                // to avoid duplicates
                while (j != n - 1 && nums[j] == nums[j + 1]) j++;
                j++;
            }
        }
    }

public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;

        // 1. Sort inputs O(nlogn)
        sort(nums.begin(), nums.end());

        int n = nums.size();

        // 2. two sum on all inputs
        // O(n^2)
        for (int i = 0; i < n; i++) {
            // two pointers
            int j = i + 1, k = n - 1;

            // perform a two sum as -nums[i] as target sum
            twoSum(nums, i, j, k, ans);

            // to avoid duplicates
            while (i != n - 1 && nums[i] == nums[i + 1]) i++;
        }

        for (auto triplet : ans) {
            sort(triplet.begin(), triplet.end());
        }

        return ans;
    }
};

using namespace std;

#include <vector>
#include <iostream>
#include <algorithm>

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        if (nums.size() < 3)
            return result;

        // sort the input:
        sort(nums.begin(), nums.end());

        // for all elements:
        for (int i = 0; i < nums.size() - 2; ++i) {
            // remove duplicates:
            if (nums[i] == nums[i + 1]) {
                ++i;
            }

            twoSum(result, nums, i);
        }

        return result;
    }

    void twoSum(vector<vector<int>>& result, vector<int>& nums, int currrentIndex) {
        int start = currrentIndex + 1, end = nums.size() - 1;
        while (start < end) {
            int sum = nums[start] + nums[end];
            if (nums[currrentIndex] + sum == 0) {
                result.push_back({ currrentIndex , start, end });
            }

            while (start < end && nums[start] == nums[start + 1]) {
                ++start;
            }

            while (end > start && nums[end] == nums[end - 1]) {
                --end;
            }

            if (sum > nums[currrentIndex])
                --end;
            else
                ++start;
        }
    }
};