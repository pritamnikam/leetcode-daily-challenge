/*
Jump Game

You are given an integer array nums. You are initially positioned at the array's first index, 
and each element in the array represents your maximum jump length at that position.

Return true if you can reach the last index, or false otherwise.

Example 1:

Input: nums = [2,3,1,1,4]
Output: true
Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.

Example 2:
Input: nums = [3,2,1,0,4]
Output: false
Explanation: You will always arrive at index 3 no matter what. Its maximum jump length is 0, which makes it impossible to reach the last index.


Constraints:
1 <= nums.length <= 104
0 <= nums[i] <= 105


*/
using namespace std;
#include <vector>

class Solution {
    // Returns Minimum number of jumps to reach end
    int JumpSteps(vector<int>& arr, int n) {
        // jumps[0] will hold the result
        int* jumps = new int[n];
        int min;

        // Minimum number of jumps needed to reach last element from last
        // elements itself is always 0
        jumps[n - 1] = 0;

        // Start from the second element, move from right to left and
        // construct the jumps[] array where jumps[i] represents minimum number
        // of jumps needed to reach arr[m-1] from arr[i]
        for (int i = n - 2; i >= 0; i--) {
            // If arr[i] is 0 then arr[n-1] can't be reached from here
            if (arr[i] == 0)
                jumps[i] = INT_MAX;

            // If we can directly reach to the end point from here then
            // jumps[i] is 1
            else if (arr[i] >= n - i - 1)
                jumps[i] = 1;

            // Otherwise, to find out the minimum number of jumps needed to reach
            // arr[n-1], check all the points reachable from here and jumps[]
            // value for those points
            else {
                // initialize min value
                min = INT_MAX;

                // following loop checks with all reachable points and takes
                // the minimum
                for (int j = i + 1; j < n && j <= arr[i] + i; j++) {
                    if (min > jumps[j])
                        min = jumps[j];
                }

                // Handle overflow
                if (min != INT_MAX)
                    jumps[i] = min + 1;
                else
                    jumps[i] = min; // or INT_MAX
            }
        }

        return jumps[0];
    }
public:
    bool canJump(vector<int>& nums) {
        int steps = JumpSteps(nums, nums.size());
        return steps != INT_MAX;
    }
};