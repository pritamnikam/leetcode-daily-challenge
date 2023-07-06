/*
209. Minimum Size Subarray Sum
https://leetcode.com/problems/minimum-size-subarray-sum/description/

Given an array of positive integers nums and a positive integer target, return the minimal length of a
subarray
 whose sum is greater than or equal to target. If there is no such subarray, return 0 instead.



Example 1:

Input: target = 7, nums = [2,3,1,2,4,3]
Output: 2
Explanation: The subarray [4,3] has the minimal length under the problem constraint.
Example 2:

Input: target = 4, nums = [1,4,4]
Output: 1
Example 3:

Input: target = 11, nums = [1,1,1,1,1,1,1,1]
Output: 0


Constraints:

1 <= target <= 109
1 <= nums.length <= 105
1 <= nums[i] <= 104

*/

using namespace std;

#include <iostream>
#include <vector>

namespace {
    class Solution {
    public:
        int minSubArrayLen(int target, vector<int>& nums) {
            int left = 0, right = 0, sumOfCurrentWindow = 0;
            int result = INT_MAX;

            for (right = 0; right < nums.size(); right++) {
                sumOfCurrentWindow += nums[right];

                while (sumOfCurrentWindow >= target) {
                    result = min(result, right - left + 1);
                    sumOfCurrentWindow -= nums[left];
                    left++;
                }
            }

            return result == INT_MAX ? 0 : result;
        }
    };
}
