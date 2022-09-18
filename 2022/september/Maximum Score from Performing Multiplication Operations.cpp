/*
1770. Maximum Score from Performing Multiplication Operations
https://leetcode.com/problems/maximum-score-from-performing-multiplication-operations/

You are given two integer arrays nums and multipliers of size n and m respectively, where n >= m. The arrays are 1-indexed.

You begin with a score of 0. You want to perform exactly m operations. On the ith operation (1-indexed), you will:

Choose one integer x from either the start or the end of the array nums.
Add multipliers[i] * x to your score.
Remove x from the array nums.
Return the maximum score after performing m operations.



Example 1:

Input: nums = [1,2,3], multipliers = [3,2,1]
Output: 14
Explanation: An optimal solution is as follows:
- Choose from the end, [1,2,3], adding 3 * 3 = 9 to the score.
- Choose from the end, [1,2], adding 2 * 2 = 4 to the score.
- Choose from the end, [1], adding 1 * 1 = 1 to the score.
The total score is 9 + 4 + 1 = 14.
Example 2:

Input: nums = [-5,-3,-3,-2,7,1], multipliers = [-10,-5,3,4,6]
Output: 102
Explanation: An optimal solution is as follows:
- Choose from the start, [-5,-3,-3,-2,7,1], adding -5 * -10 = 50 to the score.
- Choose from the start, [-3,-3,-2,7,1], adding -3 * -5 = 15 to the score.
- Choose from the start, [-3,-2,7,1], adding -3 * 3 = -9 to the score.
- Choose from the end, [-2,7,1], adding 1 * 4 = 4 to the score.
- Choose from the end, [-2,7], adding 7 * 6 = 42 to the score.
The total score is 50 + 15 - 9 + 4 + 42 = 102.


Constraints:

n == nums.length
m == multipliers.length
1 <= m <= 103
m <= n <= 105
-1000 <= nums[i], multipliers[i] <= 1000

*/

using namespace std;

#include <vector>
#include <algorithm>

namespace {
	class Solution {
	public:
        int maximumScore(vector<int>& nums, vector<int>& multipliers) {
            // For Right Pointer
            int n = nums.size();

            // Number of Operations
            int m = multipliers.size();

            if (m * n == 0) return 0;

            vector<int> dp(m + 1, 0);

            for (int op = m - 1; op >= 0; --op) {
                vector<int> next_row = dp;

                for (int left = op; left >= 0; --left) {
                    dp[left] = max(
                        multipliers[op] * nums[left] + next_row[left + 1],
                        multipliers[op] * nums[n - 1 - (op - left)] + next_row[left]
                    );
                }
            }

            return dp[0];
        }

    private:
        // alternatively
        int dp[1000][1000];

        int answer_dp(vector<int>& nums, vector<int>& multi, int i, int l, int r) {
            // index reached end
            if (i == multi.size())
                return 0;

            // already have answer
            if (dp[l][i] != -1)
                return dp[l][i];

            // recurrsively solve w/ first and last selection
            int first = multi[i] * nums[l] + answer_dp(nums, multi, i + 1, l + 1, r);
            int last = multi[i] * nums[r] + answer_dp(nums, multi, i + 1, l, r - 1);

            // maximum from sub-problems
            dp[l][i] = max(first, last);
            return dp[l][i];
        }

        int maximumScoreRecurrsion(vector<int>& nums, vector<int>& multi) {
            memset(dp, -1, sizeof(dp));
            return answer_dp(nums,
                             multi, 
                             0, 0, 
                             nums.size() - 1);
        }
	};
}