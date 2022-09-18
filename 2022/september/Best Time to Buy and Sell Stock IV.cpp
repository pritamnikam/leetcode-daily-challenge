/*
188. Best Time to Buy and Sell Stock IV
https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/

You are given an integer array prices where prices[i] is the price of a given stock on the ith day, and an integer k.

Find the maximum profit you can achieve. You may complete at most k transactions.

Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).



Example 1:

Input: k = 2, prices = [2,4,1]
Output: 2
Explanation: Buy on day 1 (price = 2) and sell on day 2 (price = 4), profit = 4-2 = 2.
Example 2:

Input: k = 2, prices = [3,2,6,5,0,3]
Output: 7
Explanation: Buy on day 2 (price = 2) and sell on day 3 (price = 6), profit = 6-2 = 4. Then buy on day 5 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.


Constraints:

1 <= k <= 100
1 <= prices.length <= 1000
0 <= prices[i] <= 1000


*/

using namespace std;

#include <vector>

namespace {
    class Solution {
        /*
        Constraints:
            0 <= k <= 100
            0 <= prices.length <= 1000
            0 <= prices[i] <= 1000
        */

        int dp[1000][2][500];

        int Solve(int day, bool own, int k, vector<int>& prices) {
            // no days left
            if (day == prices.size())
                return 0;

            if (dp[day][own][k] != -1)
                return dp[day][own][k];

            if (own) {
                // sell if allowed
                int op1 = (k > 0) ? prices[day] + Solve(day + 1, false, k - 1, prices) : 0;
                int op2 = Solve(day + 1, true, k, prices);

                return dp[day][own][k] = max(op1, op2);

            }
            else {
                // buy
                int op1 = -prices[day] + Solve(day + 1, true, k, prices);
                int op2 = Solve(day + 1, false, k, prices);

                return dp[day][own][k] = max(op1, op2);
            }
        }

    public:
        int maxProfit(int k, vector<int>& prices) {
            memset(dp, -1, sizeof dp);
            return Solve(0, false, k, prices);
        }
    };
}