/*
137. Single Number II
https://leetcode.com/problems/single-number-ii/

Given an integer array nums where every element appears three times except for one, which appears exactly once. Find the single element and return it.
You must implement a solution with a linear runtime complexity and use only constant extra space.

Example 1:
Input: nums = [2,2,3,2]
Output: 3

Example 2:
Input: nums = [0,1,0,1,0,1,99]
Output: 99

Constraints:
1 <= nums.length <= 3 * 104
-231 <= nums[i] <= 231 - 1
Each element in nums appears exactly three times except for one element which appears once.

*/

using namespace std;

#include <iostream>
#include <vector>

namespace {
    class Solution {
    public:
        int singleNumber(vector<int>& nums) {
            int ans = 0;
            for (int i = 0; i < 32; i++) {
                int sum = 0;
                for (const int num : nums) {
                    sum += num >> i & 1;
                }

                sum %= 3;
                ans |= sum << i;
            }

            return ans;
        }

    private:
        int singleNumber2(vector<int>& nums) {
            int ones = 0;
            int twos = 0;

            for (const int num : nums) {
                ones ^= (num & ~twos);
                twos ^= (num & ~ones);
            }

            return ones;
        }
    };
} // namespace
