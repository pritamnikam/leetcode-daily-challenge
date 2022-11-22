/*
279. Perfect Squares
https://leetcode.com/problems/perfect-squares/

Given an integer n, return the least number of perfect square numbers that sum to n.

A perfect square is an integer that is the square of an integer; in other words,
it is the product of some integer with itself. For example, 1, 4, 9, and 16 are 
perfect squares while 3 and 11 are not.

Example 1:
Input: n = 12
Output: 3
Explanation: 12 = 4 + 4 + 4.

Example 2:
Input: n = 13
Output: 2
Explanation: 13 = 4 + 9.


Constraints:
1 <= n <= 104

*/

using namespace std;

#include <vector>
#include <iostream>

namespace {
    class Solution {
    public:
        int numSquares(int n) {
            vector<int> dp(n + 1, INT_MAX);
            dp[0] = 0; // base case

            // pre-calculate the square numbers.
            int number_of_squares = (int)sqrt(n) + 1;
            vector<int> squares(number_of_squares);
            for (int i = 1; i < number_of_squares; ++i) {
                squares[i] = i * i;
            }

            for (int i = 1; i <= n; ++i) {
                for (int j = 1; j < number_of_squares; ++j) {
                    if (i < squares[j]) break;
                    dp[i] = min(
                        dp[i],
                        1 + dp[i - squares[j]]
                    );
                }
            }

            return dp[n];
        }
    };
}


void testPerfectSquares() {
    cout << "Perfect Squares: " << Solution().numSquares(12) << endl;
}
