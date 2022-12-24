/*
790. Domino and Tromino Tiling
https://leetcode.com/problems/domino-and-tromino-tiling/

You have two types of tiles: a 2 x 1 domino shape and a tromino shape. You may rotate these shapes.
Given an integer n, return the number of ways to tile an 2 x n board. Since the answer may be very large, return it modulo 109 + 7.

In a tiling, every square must be covered by a tile. Two tilings are different if and only if there are two 4-directionally adjacent 
cells on the board such that exactly one of the tilings has both squares occupied by a tile.


Example 1:
Input: n = 3
Output: 5
Explanation: The five different ways are show above.

Example 2:
Input: n = 1
Output: 1

Constraints:
1 <= n <= 1000

*/

using namespace std;

#include <iostream>
#include <vector>


namespace {
    static int MOD = 1000000007;

    class Solution {
    public:
        // f(n)=f(n−1)+f(n−2)+2∑n−3. 
        // Then subtract f(n)−f(n−1)=f(n−1)+f(n−3). 
        // Thus f(n)=2f(n−1)+f(n−3), which is in the OEIS.
        int numTilings(int n) {
            if (n == 1) return 1;
            if (n == 2) return 2;
            vector<long long> dp(n + 1, 0);
            dp[0] = 1; dp[1] = 1; dp[2] = 2;
            for (int i = 3; i <= n; i++) {
                // f(n) = 2 * f(n−1) + f(n−3)
                dp[i] = (2 * dp[i - 1] + dp[i - 3]) % MOD;
            }
            return dp[n];
        }
    };

} // namespae

void testDominoAndTrominoTiling() {
    cout << "Domino and Tromino Tiling: " << Solution().numTilings(3) << endl;
}
