/*
239. Sliding Window Maximum
https://leetcode.com/problems/sliding-window-maximum/

You are given an array of integers nums, there is a sliding window of size k which is
moving from the very left of the array to the very right. You can only see the k numbers
in the window. Each time the sliding window moves right by one position.

Return the max sliding window.

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


Input: nums = [1], k = 1
Output: [1]


Constraints:

1 <= nums.length <= 105
-104 <= nums[i] <= 104
1 <= k <= nums.length

*/


using namespace std;

#include <vector>
#include <list>

namespace {
    class Solution {
    public:
        vector<int> maxSlidingWindow(vector<int>& nums, int k) {
            int startWindow = 0,
                n = nums.size();

            list<int> l;
            vector<int> answer;

            for (int endWindow = 0; endWindow < n; ++endWindow) {
                // empty
                while (!l.empty() and
                    l.back() < nums[endWindow]) {
                    l.pop_back();
                }

                l.push_back(nums[endWindow]);

                // window length
                if (endWindow - startWindow + 1 >= k) {
                    answer.push_back(l.front());

                    if (l.front() == nums[startWindow]) {
                        l.pop_front();
                    }

                    ++startWindow;
                }
            }

            return answer;
        }
    };
}

void testMaxSlidingWindow() {
    /*
        Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
        Output: [3,3,5,5,6,7]
    */

    vector<int>  nums = { 1, 3, -1, -3, 5, 3, 6, 7 };
    int k = 3;

    vector<int> answer = Solution().maxSlidingWindow(nums, k);

    /*
        Input: nums = [1, 3, 1, 2, 0, 5], k = 3
        Output: [3,3,2,5]
    */

    nums = { 1, 3, 1, 2, 0, 5 };
    k = 3;
    answer = Solution().maxSlidingWindow(nums, k);
}