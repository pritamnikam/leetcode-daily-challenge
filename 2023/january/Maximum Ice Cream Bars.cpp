/*
1833. Maximum Ice Cream Bars
https://leetcode.com/problems/maximum-ice-cream-bars/

It is a sweltering summer day, and a boy wants to buy some ice cream bars.

At the store, there are n ice cream bars. You are given an array costs of length n, where costs[i] is the price of the ith ice cream bar in coins. The boy initially has coins coins to spend, and he wants to buy as many ice cream bars as possible.

Return the maximum number of ice cream bars the boy can buy with coins coins.

Note: The boy can buy the ice cream bars in any order.



Example 1:

Input: costs = [1,3,2,4,1], coins = 7
Output: 4
Explanation: The boy can buy ice cream bars at indices 0,1,2,4 for a total price of 1 + 3 + 2 + 1 = 7.
Example 2:

Input: costs = [10,6,8,7,7,8], coins = 5
Output: 0
Explanation: The boy cannot afford any of the ice cream bars.
Example 3:

Input: costs = [1,6,3,1,2,5], coins = 20
Output: 6
Explanation: The boy can buy all the ice cream bars for a total price of 1 + 6 + 3 + 1 + 2 + 5 = 18.


Constraints:

costs.length == n
1 <= n <= 105
1 <= costs[i] <= 105
1 <= coins <= 108

*/

using namespace std;

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

namespace {
    class Solution {
    public:
        int maxIceCream(vector<int>& costs, int coins) {
            
            priority_queue<int, vector<int>, greater<>> maxHeap;

            for (int cost : costs)
                maxHeap.push(cost);

            int maxIcecreamBars = 0;
            while (!maxHeap.empty() && coins >= maxHeap.top()) {
                maxIcecreamBars++;
                coins -= maxHeap.top();
                maxHeap.pop();
            }

            return maxIcecreamBars;
        }
    };
} // namespace

void testMaximumIceCreamBars() {
    // Input: costs = [1,3,2,4,1], coins = 7, Output: 4
    vector<int> costs = { 1, 3, 2, 4, 1 };
    int coins = 7;
    cout << "Maximum Ice Cream Bars: " << Solution().maxIceCream(costs, coins) << endl;

    // Input: costs = [10,6,8,7,7,8], coins = 5, Output: 0
    costs = { 10, 6, 8, 7, 7, 8 }; coins = 5;
    cout << "Maximum Ice Cream Bars: " << Solution().maxIceCream(costs, coins) << endl;

    // Input: costs = [1,6,3,1,2,5], coins = 20, Output: 6
    costs = { 1,6,3,1,2,5 }; coins = 20;
    cout << "Maximum Ice Cream Bars: " << Solution().maxIceCream(costs, coins) << endl;

}
