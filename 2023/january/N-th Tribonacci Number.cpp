/*
1137. N-th Tribonacci Number
https://leetcode.com/problems/n-th-tribonacci-number/description/

The Tribonacci sequence Tn is defined as follows:

T0 = 0, T1 = 1, T2 = 1, and Tn+3 = Tn + Tn+1 + Tn+2 for n >= 0.

Given n, return the value of Tn.



Example 1:

Input: n = 4
Output: 4
Explanation:
T_3 = 0 + 1 + 1 = 2
T_4 = 1 + 1 + 2 = 4
Example 2:

Input: n = 25
Output: 1389537


Constraints:

0 <= n <= 37
The answer is guaranteed to fit within a 32-bit integer, ie. answer <= 2^31 - 1.

*/

using namespace std;

#include <iostream>
#include <unordered_map>

namespace {
    class Solution {
    public:
        unordered_map<int, int> dp;
        int tribonacci(int n) {
            if (dp.count(n)) {
                return dp[n];
            }

            if (n < 2) return n;
            if (n == 2) return 1;

            return dp[n] = tribonacci(n - 1) + tribonacci(n - 2) + tribonacci(n - 3);
        }

        int tribonacci2(int n) {
            if (n < 0) return 0;
            vector<int> vt(n + 1, 0);
            vt[1] = 1; vt[2] = 1;
            for (int i = 3; i <= n; ++i) {
                vt[i] = vt[i - 3] + vt[i - 2] + vt[i - 1];
            }

            return vt[n];
        }
    };
}  // namespace


void testNthTribonacciNumber() {
    // Input: n = 4, Output: 4
    cout << "N-th Tribonacci Number: " << Solution().tribonacci(4) << endl;
}
