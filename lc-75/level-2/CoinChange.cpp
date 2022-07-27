/*
322. Coin Change
https://leetcode.com/problems/coin-change/

You are given an integer array coins representing coins of different denominations 
and an integer amount representing a total amount of money.

Return the fewest number of coins that you need to make up that amount.
If that amount of money cannot be made up by any combination of the coins, return -1.

You may assume that you have an infinite number of each kind of coin.



Example 1:

Input: coins = [1,2,5], amount = 11
Output: 3
Explanation: 11 = 5 + 5 + 1
Example 2:

Input: coins = [2], amount = 3
Output: -1
Example 3:

Input: coins = [1], amount = 0
Output: 0


Constraints:

1 <= coins.length <= 12
1 <= coins[i] <= 231 - 1
0 <= amount <= 104


*/


using namespace std;

#include <iostream>
#include <vector>

namespace {

    class Solution {
    public:
        // Space: O(n * s), Time: O(n * s)
        int coinChange2D(vector<int>& coins, int amount) {
            int n = coins.size();
            vector<vector<int>> dp(n, vector<int>(amount + 1, 0));

            // with amount as '0' need '0' coins.
            for (int i = 0; i < n; ++i)
                dp[i][0] = 0;

            int op1 = numeric_limits<int>::max(),
                op2 = numeric_limits<int>::max();

            for (int i = 0; i < n; ++i) {
                for (int j = 1; j <= amount; ++j) {

                    // we exclude coin
                    if (i > 0)
                        op1 = dp[i - 1][j];

                    // we include coin
                    if (coins[i] <= j) {
                        op2 = dp[i][j - coins[i]];

                        if (op2 < numeric_limits<int>::max())
                            op2 += 1;
                    }


                    dp[i][j] = min(op1, op2);
                }
            }

            return (dp[n - 1][amount] == numeric_limits<int>::max()) 
                        ? -1 : dp[n - 1][amount];
        }
        
        // Space: O(n), Time: O(n * s)
        int coinChange(vector<int>& coins, int amount) {
            vector<int> dp(amount + 1, amount + 1);
            dp[0] = 0;

            for (int i = 1; i <= amount; ++i) {
                for (int coin: coins){
                    if (i - coin < 0) continue;

                    dp[i] = min(dp[i], dp[i-coin] + 1);
                }
            }
            return dp[amount] == amount + 1 ? -1 : dp[amount];
        }
    };
} // namesapce
