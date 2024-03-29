/*
70. Climbing Stairs
https://leetcode.com/problems/climbing-stairs/

You are climbing a staircase. It takes n steps to reach the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?



Example 1:

Input: n = 2
Output: 2
Explanation: There are two ways to climb to the top.
1. 1 step + 1 step
2. 2 steps
Example 2:

Input: n = 3
Output: 3
Explanation: There are three ways to climb to the top.
1. 1 step + 1 step + 1 step
2. 1 step + 2 steps
3. 2 steps + 1 step


Constraints:

1 <= n <= 45

*/

using namespace std;

#include <iostream>
#include <unordered_map>


namespace {
    class Solution {
    public:
        unordered_map<int, int> cache;
        int climbStairsMemo(int n) {
            if (cache.count(n)) {
                return cache[n];
            }

            // if there is only 1 stair - only one way to climb
            // if there are 2 stairs - 2 ways one can climb {1, 1} & {2}
            if (n == 1 || n == 2) {
                cache[n] = n;
                return cache[n];
            }

            // follows fibonacci number pattern
            cache[n] = climbStairsMemo(n - 1) + climbStairsMemo(n - 2);
            return cache[n];
        }

        int climbStairs(int n) {
            if (n == 1) { return 1; }

            vector<int> dp(n + 1);
            dp[1] = 1;
            dp[2] = 2;

            for (int i = 3; i <= n; ++i) {
                dp[i] = dp[i - 1] + dp[i - 2];
            }

            return dp[n];
        }
    };
}

void testClimbingStairs() {
    // Input: n = 3, Output: 3
    cout << "Climbing Stairs: " << Solution().climbStairs(3) << endl;
}
