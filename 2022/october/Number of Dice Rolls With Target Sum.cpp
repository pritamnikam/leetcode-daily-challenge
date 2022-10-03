/*
1155. Number of Dice Rolls With Target Sum
https://leetcode.com/problems/number-of-dice-rolls-with-target-sum/

You have n dice and each die has k faces numbered from 1 to k.

Given three integers n, k, and target, return the number of possible ways (out of the kn total ways) to roll the dice so the sum of the face-up numbers equals target. Since the answer may be too large, return it modulo 109 + 7.



Example 1:

Input: n = 1, k = 6, target = 3
Output: 1
Explanation: You throw one die with 6 faces.
There is only one way to get a sum of 3.
Example 2:

Input: n = 2, k = 6, target = 7
Output: 6
Explanation: You throw two dice, each with 6 faces.
There are 6 ways to get a sum of 7: 1+6, 2+5, 3+4, 4+3, 5+2, 6+1.
Example 3:

Input: n = 30, k = 30, target = 500
Output: 222616187
Explanation: The answer must be returned modulo 109 + 7.


Constraints:

1 <= n, k <= 30
1 <= target <= 1000

*/


using namespace std;

#include <iostream>
#include <vector>
#include <unordered_map>
#include <math.h>

namespace {
	class Solution {
	
		const int mod = pow(10, 9) + 7;

		inline void solve(int f,
			int target,
			vector<int>& ways) {

			// target sum:
			for (int i = target; i >= 0; i--) {

				int way = 0;

				for (int y = i - 1;
					y >= max(0, i - f);
					y--) {

					way = (way + ways[y]) % mod;
				}

				ways[i] = way;
			}
		}

	public:
		int numRollsToTarget(int d,
			int f,
			int target) {

			vector<int> ways(target + 1);
			ways[0] = 1;

			for (int x = 1; x <= d; x++) {
				solve(f, target, ways);
			}

			return ways[target];
		}
		

private:
		int numRollsToTargetDP(int d, int f, int target) {
			vector<int> dp(target + 1, 1);
			int i, j, k;
			for (i = 1; i <= d; ++i) {
				for (k = target; k >= (i == d ? target : 0); --k) {
					for (j = k - 1, dp[k] = 0; j >= max(0, k - f); --j) {
						dp[k] = (dp[k] + dp[j]) % 1000000007;
					}
				}
			}
			return dp[target];
		}

		int numRollsToTarget2(int n, int k, int target) {
			long ans = recurse(n, k, target);
			return ans % 1000000007;
		}

		long recurse(int n, int k, int target) {
			if (n <= 0 || k <= 0 || target < n || target > n * k) {
				return 0;
			}

			if (n == 1 and k >= target) {
				return 1;
			}

			long sum = 0;
			for (int i = min(target, k); 
					 i > 0 && ((target - i) <= ((n - 1) * k));
					 i--) {
				sum += recurse(n - 1, k, target - i);
			}

			return sum;
		}
	};
}
