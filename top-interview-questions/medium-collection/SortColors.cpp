/*
Sort Colors

Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.

We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.

You must solve this problem without using the library's sort function.



Example 1:

Input: nums = [2,0,2,1,1,0]
Output: [0,0,1,1,2,2]
Example 2:

Input: nums = [2,0,1]
Output: [0,1,2]


Constraints:

n == nums.length
1 <= n <= 300
nums[i] is either 0, 1, or 2.


Follow up: Could you come up with a one-pass algorithm using only constant extra space?


*/


using namespace std;

#include <vector>

class Solution {
public:
    void sortColors1(vector<int>& nums) {
        int colors[3] = { 0, 0, 0 };
        for (int n : nums)
            colors[n]++;

        int count = 0;
        for (int i = 0; i < 3; ++i) {
            while (colors[i] != 0) {
                colors[i]--;
                nums[count++] = i;
            }
        }
    }


    // 2 pointers
    void sortColors(vector<int>& nums) {
        //zero represent range of 0's and two represent range of2's
        int zero = 0, two = nums.size() - 1, p = 0;
        while (p <= two) {

            // move to 2's range i.e right
            if (nums[p] == 2) {
                swap(nums[p], nums[two]);
                two--;
            }
            // move to 0's range i.e left
            else if (nums[p] == 0) {
                swap(nums[zero], nums[p]);
                zero++;
                p++;
            }
            else p++;
        }
    }
};