/*
Coin Change

You are given an integer array coins representing coins of different denominations and an integer amount
representing a total amount of money.

Return the fewest number of coins that you need to make up that amount. If that amount of money cannot 
be made up by any combination of the coins, return -1.

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

class Solution {
    static const int kSum = 10007;
    static const int kSize = 15;

    int dp[kSize][kSum];

public:
    int coinChange(vector<int>& coins, int amount) {
        int size = coins.size();
        int sum = amount;

        // for all sum: if no coin or only one coin
        for (int j = 0; j <= sum; ++j) {
            dp[0][j] = INT_MAX - 1;
            dp[1][j] = (j % coins[0] == 0) ? j / coins[0] : INT_MAX - 1;
        }

        // for all coins: if sum is '0'
        for (int i = 1; i <= size; ++i)
            dp[i][0] = 0;

        // for all coins left
        for (int i = 2; i <= size; ++i) {
            // for all possible sum required
            for (int j = 1; j <= sum; ++j) {
                // 2 choices:
                // - picking the coin if coin value less than equired sum
                // - otherwise, not picking the coin
                if (coins[i - 1] <= j) {
                    dp[i][j] = min(dp[i - 1][j],
                        1 + dp[i][j - coins[i - 1]]);
                }
                else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }

        return (dp[size][sum] == INT_MAX - 1) ? -1 : dp[size][sum];
    }


    vector<vector<int>> cache;
    int coinChangeHelper(vector<int>& coins, int amount, int currentIndex) {
        // base case:
        if (currentIndex >= coins.size()) return numeric_limits<int>::max();
        if (amount == 0) return numeric_limits<int>::max();

        // short circuiting if we already know the answer
        if (cache[amount][currentIndex] != -1)
            return cache[amount][currentIndex];

        // selecting the coin only if value lesser than the amount
        int withCoin = numeric_limits<int>::max();
        if (coins[currentIndex] <= amount) {
            withCoin = 1 + coinChangeHelper(coins,
                                            amount - coins[currentIndex],
                                            currentIndex);
        }

        // without selecting the coin
        int withoutCoin = coinChangeHelper(coins,
                                           amount,
                                           currentIndex + 1);

        // memoized the count
        cache[amount][currentIndex] = min(withCoin, withoutCoin);

        // result:
        return cache[amount][currentIndex];
    }

    int coinChange(vector<int>& coins, int amount) {
        cache = vector<vector<int>>(amount + 1, vector<int>(coins.size() + 1, -1));
        return coinChangeHelper(coins, amount, 0);
    }
};