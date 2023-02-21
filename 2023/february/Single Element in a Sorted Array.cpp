/*
540. Single Element in a Sorted Array
https://leetcode.com/problems/single-element-in-a-sorted-array

You are given a sorted array consisting of only integers where every element appears exactly twice, except for one element which appears exactly once.

Return the single element that appears only once.

Your solution must run in O(log n) time and O(1) space.



Example 1:

Input: nums = [1,1,2,3,3,4,4,8,8]
Output: 2
Example 2:

Input: nums = [3,3,7,7,10,11,11]
Output: 10


Constraints:

1 <= nums.length <= 105
0 <= nums[i] <= 105

*/

using namespace std;

#include <iostream>
#include <vector>

namespace {
    class Solution {
    public:
        int singleNonDuplicate(vector<int>& nums) {
            int n = nums.size(), l = 0, r = n - 1, m;
            while (l < r) {
                m = l + (r - l) / 2;
                if (m % 2 == 0) {
                    if (nums[m] == nums[m + 1]) l = m + 1;
                    else { r = m; }
                }
                else {
                    if (nums[m] != nums[m + 1]) l = m + 1;
                    else { r = m; }
                }
            }
            return nums[l];
        }
    };
}

void testSingleElementInSortedArray() {
    // Input: nums = [1,1,2,3,3,4,4,8,8] | Output: 2
    vector<int> nums = { 1, 1, 2, 3, 3, 4, 4, 8, 8 };
    cout << "Single Element in a Sorted Array: " << Solution().singleNonDuplicate(nums) << endl;
}
