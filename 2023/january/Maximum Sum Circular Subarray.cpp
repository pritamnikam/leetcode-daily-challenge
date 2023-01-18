/*
918. Maximum Sum Circular Subarray
https://leetcode.com/problems/maximum-sum-circular-subarray/

Given a circular integer array nums of length n, return the maximum possible sum of a 
non-empty subarray of nums.

A circular array means the end of the array connects to the beginning of the array. 
Formally, the next element of nums[i] is nums[(i + 1) % n] and the previous element 
of nums[i] is nums[(i - 1 + n) % n].

A subarray may only include each element of the fixed buffer nums at most once. 
Formally, for a subarray nums[i], nums[i + 1], ..., nums[j], there does not exist
i <= k1, k2 <= j with k1 % n == k2 % n.

Example 1:
Input: nums = [1,-2,3,-2]
Output: 3
Explanation: Subarray [3] has maximum sum 3.

Example 2:
Input: nums = [5,-3,5]
Output: 10
Explanation: Subarray [5,5] has maximum sum 5 + 5 = 10.

Example 3:
Input: nums = [-3,-2,-3]
Output: -2
Explanation: Subarray [-2] has maximum sum -2.

Constraints:
n == nums.length
1 <= n <= 3 * 104
-3 * 104 <= nums[i] <= 3 * 104

*/

using namespace std;

#include <iostream>
#include <vector>

namespace {
    class Solution {
    public:
        int maxSubarraySumCircular(vector<int>& nums) {
            // S: sum of A
            int S = 0;
            for (int x : nums) {
                S += x;
            }

            if (nums.size() == 1) {
                return S;
            }

            // ans1: answer for one-interval subarray
            int ans1 = INT_MIN;
            int cur = INT_MIN;
            for (int x : nums) {
                cur = x + max(cur, 0);
                ans1 = max(ans1, cur);
            }

            // ans2: answer for two-interval subarray, interior in A[1:]
            int ans2 = INT_MAX;
            cur = INT_MAX;
            for (int i = 1; i < nums.size(); ++i) {
                cur = nums[i] + min(cur, 0);
                ans2 = min(ans2, cur);
            }
            ans2 = S - ans2;

            // ans3: answer for two-interval subarray, interior in A[:-1]
            int ans3 = INT_MAX;
            cur = INT_MAX;
            for (int i = 0; i < nums.size() - 1; ++i) {
                cur = nums[i] + min(cur, 0);
                ans3 = min(ans3, cur);
            }

            return max(ans1, max(ans2, ans3));
        }

    };
}  // namespace

void testMaximumSumCircularSubarray() {
    // Input: nums = [1,-2,3,-2], Output: 3
    vector<int> nums  = { 1, -2, 3, -2 };
    cout << "Maximum Sum Circular Subarray: " << Solution().maxSubarraySumCircular(nums) << endl;
}
