/*
Best Time to Buy and Sell Stock II

You are given an integer array prices where prices[i] is the price of a given stock on the ith day.
On each day, you may decide to buy and/or sell the stock. 
You can only hold at most one share of the stock at any time. 
However, you can buy it then immediately sell it on the same day.
Find and return the maximum profit you can achieve.

Example 1:
Input: prices = [7,1,5,3,6,4]
Output: 7
Explanation: Buy on day 2 (price = 1) and sell on day 3 (price = 5), profit = 5-1 = 4.
Then buy on day 4 (price = 3) and sell on day 5 (price = 6), profit = 6-3 = 3.
Total profit is 4 + 3 = 7.


Example 2:
Input: prices = [1,2,3,4,5]
Output: 4
Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
Total profit is 4.
Example 3:

Input: prices = [7,6,4,3,1]
Output: 0
Explanation: There is no way to make a positive profit, so we never buy the stock to achieve the maximum profit of 0.


Constraints:

1 <= prices.length <= 3 * 104
0 <= prices[i] <= 104

Summary
We have to determine the maximum profit that can be obtained by making the transactions (no limit on the number of transactions done). 
For this we need to find out those sets of buying and selling prices which together lead to the maximization of profit.

Solution Article
Approach 1: Brute Force
In this case, we simply calculate the profit corresponding to all the possible sets of transactions and 
find out the maximum profit out of them.

Complexity Analysis

Time complexity : O(n^n). Recursive function is called n^n times.

Space complexity : O(n). Depth of recursion is nn.
*/

using namespace std;
#include <vector>

class Solution {
public :
    int maxProfit(vector<int> prices) {
        return calculate(prices, 0);
    }

     int calculate(vector<int> prices, int s) {
        if (s >= prices.size())
            return 0;

        int max = 0;
        for (int start = s; start < prices.size(); start++) {
            int maxprofit = 0;
            for (int i = start + 1; i < prices.size(); i++) {
                if (prices[start] < prices[i]) {
                    int profit = calculate(prices, i + 1) + prices[i] - prices[start];
                    if (profit > maxprofit)
                        maxprofit = profit;
                }
            }
            if (maxprofit > max)
                max = maxprofit;
        }
        return max;
    }
};

/*
Approach 2: Peak Valley Approach

Algorithm

Say the given array is:

[7, 1, 5, 3, 6, 4].

If we plot the numbers of the given array on a graph, we get:

Profit Graph

If we analyze the graph, we notice that the points of interest are the consecutive valleys and peaks.

Mathematically speaking: Total Profit= \sum_{i}(height(peak_i)-height(valley_i))TotalProfit=∑
i
​
 (height(peak
i
​
 )−height(valley
i
​
 ))

The key point is we need to consider every peak immediately following a valley to maximize the profit. In case we skip one of the peaks (trying to obtain more profit), we will end up losing the profit over one of the transactions leading to an overall lesser profit.

For example, in the above case, if we skip peak_ipeak
i
​
  and valley_jvalley
j
​
  trying to obtain more profit by considering points with more difference in heights, the net profit obtained will always be lesser than the one obtained by including them, since CC will always be lesser than A+BA+B.

Complexity Analysis
Time complexity : O(n). Single pass.
Space complexity : O(1). Constant space required.

*/

class Solution {
public:
    int maxProfit(vector<int> prices) {
        int i = 0;
        int valley = prices[0];
        int peak = prices[0];
        int maxprofit = 0;
        while (i < prices.size() - 1) {
            // valley
            while (i < prices.size() - 1 && prices[i] >= prices[i + 1]) i++;
            valley = prices[i];

            // peak
            while (i < prices.size() - 1 && prices[i] <= prices[i + 1]) i++;
            peak = prices[i];

            // profit
            maxprofit += peak - valley;
        }
        return maxprofit;
    }
};

/*
Approach 3: Simple One Pass
Algorithm

This solution follows the logic used in Approach 2 itself, but with only a slight variation. 
In this case, instead of looking for every peak following a valley, we can simply go on crawling 
over the slope and keep on adding the profit obtained from every consecutive transaction. 

In the end,we will be using the peaks and valleys effectively, but we need not track the costs 
corresponding to the peaks and valleys along with the maximum profit, but we can directly keep 
on adding the difference between the consecutive numbers of the array if the second number is 
larger than the first one, and at the total sum we obtain will be the maximum profit. 

This approach will simplify the solution. This can be made clearer by taking this example:

[1, 7, 2, 3, 6, 7, 6, 7]

The graph corresponding to this array is:

Profit Graph

From the above graph, we can observe that the sum A+B+CA+B+C is equal to the difference DD corresponding 
to the difference between the heights of the consecutive peak and valley.


Complexity Analysis
Time complexity : O(n). Single pass.
Space complexity : O(1). Constant space required.

*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        for (int i = 0; i < prices.size() - 1; ++i) {
            if (prices[i] < prices[i + 1])
                profit += prices[i + 1] - prices[i];
        }

        return profit;
    }
};