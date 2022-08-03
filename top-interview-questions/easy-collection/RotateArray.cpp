/*
Rotate Array

Given an array, rotate the array to the right by k steps, where k is non-negative.



Example 1:

Input: nums = [1,2,3,4,5,6,7], k = 3
Output: [5,6,7,1,2,3,4]
Explanation:
rotate 1 steps to the right: [7,1,2,3,4,5,6]
rotate 2 steps to the right: [6,7,1,2,3,4,5]
rotate 3 steps to the right: [5,6,7,1,2,3,4]
Example 2:

Input: nums = [-1,-100,3,99], k = 2
Output: [3,99,-1,-100]
Explanation:
rotate 1 steps to the right: [99,-1,-100,3]
rotate 2 steps to the right: [3,99,-1,-100]


Constraints:

1 <= nums.length <= 105
-231 <= nums[i] <= 231 - 1
0 <= k <= 105


Follow up:

Try to come up with as many solutions as you can. There are at least three different ways to solve this problem.
Could you do it in-place with O(1) extra space?

*/
using namespace std;
#include <vector>

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if (nums.empty() || k == nums.size())
            return;

        // 0. do the rotation normalization
        int n = nums.size();
        k = k % n;
        if (k < 0) {
            k = k + n;
        }

        // 1. reverse the array
        reverse(nums, 0, n - 1);

        // 2, reverse array in range (0-k-1)
        reverse(nums, 0, k - 1);

        // 3. reverse array in range (k - end)
        reverse(nums, k, n - 1);
    }


    void swap(vector<int>& nums, int i, int j) {
        int k = nums[i];
        nums[i] = nums[j];
        nums[j] = k;
    }

    void reverse(vector<int>& nums, int start, int end) {
        while (start < end) {
            swap(nums, start, end);
            ++start;
            --end;
        }
    }
};