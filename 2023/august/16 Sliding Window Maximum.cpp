/*
239. Sliding Window Maximum
https://leetcode.com/problems/sliding-window-maximum/description/

You are given an array of integers nums, there is a sliding window of size k which is moving from the very left of the array to the very right. 
You can only see the k numbers in the window. Each time the sliding window moves right by one position.

Return the max sliding window.
Example 1:
Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
Output: [3,3,5,5,6,7]
Explanation:
Window position                Max
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7

Example 2:
Input: nums = [1], k = 1
Output: [1]


Constraints:
1 <= nums.length <= 105
-104 <= nums[i] <= 104
1 <= k <= nums.length
*/

using namespace std;


#include <iostream>
#include <deque>
#include <vector>

namespace{
    class Solution {
    public:
        vector<int> maxSlidingWindow(vector<int>& nums, int k) {
            deque<int> dq;
            vector<int> res;
            for (int i = 0; i < k; i++) {
                while (!dq.empty() && nums[i] >= nums[dq.back()]) {
                    dq.pop_back();
                }
                dq.push_back(i);
            }
            res.push_back(nums[dq.front()]);

            for (int i = k; i < nums.size(); i++) {
                if (dq.front() == i - k) {
                    dq.pop_front();
                }
                while (!dq.empty() && nums[i] >= nums[dq.back()]) {
                    dq.pop_back();
                }

                dq.push_back(i);
                res.push_back(nums[dq.front()]);
            }

            return res;
        }
    };
}  // namespace
