/*
Move Zeroes

Solution
Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.

Note that you must do this in-place without making a copy of the array.



Example 1:

Input: nums = [0,1,0,3,12]
Output: [1,3,12,0,0]
Example 2:

Input: nums = [0]
Output: [0]


Constraints:

1 <= nums.length <= 104
-231 <= nums[i] <= 231 - 1


Follow up: Could you minimize the total number of operations done?

*/


using namespace std;

#include <vector>
#include <unordered_map>


class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int readIndex = 0, writeIndex = 0;
        while (readIndex < nums.size()) {
            if (nums[readIndex] != 0) {
                nums[writeIndex] = nums[readIndex];
                ++writeIndex;
            }
            ++readIndex;
        }

        while (writeIndex < nums.size()) {
            nums[writeIndex] = 0;
            ++writeIndex;
        }
    }
};

class Solution2 {
public:
    void moveZeroes(vector<int>& nums) {
        // 2 pointer approach
        int firstPointer = 0;
        int secondPointer = 0;

        // move the non '0' to left of the array
        while (firstPointer < nums.size()) {
            if (nums[firstPointer] != 0) {
                nums[secondPointer] = nums[firstPointer];
                ++secondPointer;
            }

            ++firstPointer;
        }

        // fill with '0'
        while (secondPointer < nums.size()) {
            nums[secondPointer] = 0;
            ++secondPointer;
        }
    }
};