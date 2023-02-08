/*
45. Jump Game II
https://leetcode.com/problems/jump-game-ii/

You are given a 0-indexed array of integers nums of length n. You are initially positioned at nums[0].

Each element nums[i] represents the maximum length of a forward jump from index i. In other words, if you are at nums[i], you can jump to any nums[i + j] where:

0 <= j <= nums[i] and
i + j < n
Return the minimum number of jumps to reach nums[n - 1]. The test cases are generated such that you can reach nums[n - 1].



Example 1:

Input: nums = [2,3,1,1,4]
Output: 2
Explanation: The minimum number of jumps to reach the last index is 2. Jump 1 step from index 0 to 1, then 3 steps to the last index.
Example 2:

Input: nums = [2,3,0,1,4]
Output: 2


Constraints:

1 <= nums.length <= 104
0 <= nums[i] <= 1000

*/

using namespace std;

#include <iostream>
#include <vector>
#include <unordered_map>

namespace {
    class Solution {
    public:
        unordered_map<int, int> dp;
        int jump(vector<int>& nums) {
            int n = nums.size();
            dp[0] = 0;

            for (int i = 1; i < n; i++)
                dp[i] = INT_MAX;

            for (int i = 1; i < n; i++) {
                for (int j = 0; j < i; j++) {
                    if (nums[j] >= i - j)
                        dp[i] = min(dp[i], dp[j] + 1);
                    else
                        continue;
                }
            }

            return dp[n - 1];
        }



        unordered_map<int, int> cache;
        int jump(vector<int>& nums, int currentIndex) {
            if (currentIndex >= nums.size() - 1)
                return 0;

            if (cache.count(currentIndex))
                return cache[currentIndex];

            int solution = INT_MAX - 10;
            for (int i = 1; i <= nums[currentIndex]; ++i) {
                solution = min(solution,
                    1 + jump(nums, i + currentIndex));
            }

            cache[currentIndex] = solution;
            return cache[currentIndex];
        }

        int jump1(vector<int>& nums) {
            if (nums.empty())
                return 0;

            return jump(nums, 0);
        }
    };

}  // namespace

void testJumpGameII() {
    // Input: nums = [2,3,1,1,4], Output: 2
    vector<int> nums = { 2, 3, 1, 1, 4 };
    cout << "Jump Game II: " << Solution().jump(nums) << endl;
}
