/*
974. Subarray Sums Divisible by K
https://leetcode.com/problems/subarray-sums-divisible-by-k/

Given an integer array nums and an integer k, return the number of non-empty
subarrays that have a sum divisible by k.

A subarray is a contiguous part of an array.

Example 1:
Input: nums = [4,5,0,-2,-3,1], k = 5
Output: 7
Explanation: There are 7 subarrays with a sum divisible by k = 5:
[4, 5, 0, -2, -3, 1], [5], [5, 0], [5, 0, -2, -3], [0], [0, -2, -3], [-2, -3]

Example 2:
Input: nums = [5], k = 9
Output: 0


Constraints:
1 <= nums.length <= 3 * 104
-104 <= nums[i] <= 104
2 <= k <= 104

*/

using namespace std;

#include <iostream>
#include <vector>

namespace {
    class Solution {
    public:
        // Approach: Prefix Sums and Counting
        // TLE, Time Complexity: O(n^2)
        int subarraysDivByK1(vector<int>& nums, int k) {
            vector<int> prefixSum(nums.size(), 0);

            prefixSum[0] = nums[0];
            for (int i = 1; i < nums.size(); ++i)
                prefixSum[i] = nums[i] + prefixSum[i - 1];

            int answer = 0;
            for (int i = 0; i < nums.size()-1; ++i) {
                for (int j = i; j < nums.size(); ++j) {
                    if ((prefixSum[j] - prefixSum[i]) % k == 0)
                        answer++;
                }
            }

            return answer;
        }

        int subarraysDivByK(vector<int>& nums, int k) {
            int n = nums.size();
            int prefixMod = 0, result = 0;

            // There are k mod groups 0...k-1.
            vector<int> modGroups(k);
            modGroups[0] = 1;

            for (int num : nums) {
                // Take modulo twice to avoid negative remainders.
                prefixMod = (prefixMod + num % k + k) % k;

                // Add the count of subarrays that have the same remainder as the current
                // one to cancel out the remainders.
                result += modGroups[prefixMod];
                modGroups[prefixMod]++;
            }

            return result;
        }
    };
} // namespace

void testSubarraySumsDivisibleByK() {
    // Input: nums = [4,5,0,-2,-3,1], k = 5, Output: 7
    vector<int> nums = { 4, 5, 0, -2, -3, 1 };
    int k = 5;

    cout << "Subarray Sums Divisible by K: " << Solution().subarraysDivByK(nums, k) << endl;
}
