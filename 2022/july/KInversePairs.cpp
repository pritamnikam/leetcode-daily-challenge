/*
629. K Inverse Pairs Array
https://leetcode.com/problems/k-inverse-pairs-array/

For an integer array nums, an inverse pair is a pair of integers [i, j] 
where 0 <= i < j < nums.length and nums[i] > nums[j].

Given two integers n and k, return the number of different arrays consist 
of numbers from 1 to n such that there are exactly k inverse pairs.

Since the answer can be huge, return it modulo 109 + 7.



Example 1:
Input: n = 3, k = 0
Output: 1
Explanation: Only the array [1,2,3] which consists of numbers from 1 to 3 has exactly 0 inverse pairs.

Example 2:
Input: n = 3, k = 1
Output: 2
Explanation: The array [1,3,2] and [2,1,3] have exactly 1 inverse pair.


Constraints:

1 <= n <= 1000
0 <= k <= 1000

*/

using namespace std;

#include <iostream>
#include <vector>

namespace{
	class Solution {
		const int M = 1000000007;
		vector<vector<int>> memo = vector<vector<int>>(1001, vector<int>(1001, 0));
	public:
		// Recurrsion with memo
		int kInversePairs1(int n, int k) {
			if (n == 0) return 0;
			if (k == 0) return 1;
			if (memo[n][k]) return memo[n][k];

			int inv = 0;
			for (int i = 0; i <= min(k, n - 1); ++i) {
				inv = (
						inv +
						kInversePairs(n - 1, k - i) 
					   ) % M;
			}

			return memo[n][k] = inv;
		}

		// Dynamic programming
		int kInversePairs(int n, int k) {
			vector<vector<int>> dp = vector<vector<int>>(n+1, vector<int>(k+1, 0));
			for (int i = 1; i <= n; ++i) {
				for (int j = 0; j <= k; ++j) {
					if (j == 0) dp[i][j] = 1;
					else {
						for (int p = 0; p <= min(j, i - 1); ++p) {
							dp[i][j] = (dp[i][j] + dp[i - 1][j - p]) % M;
						}
					}
				}
			}

			return dp[n][k];
		}
	};
}

void testKInversePairs() {
	cout << "K Inverse Pairs Array (n = 3, k = 0): " << Solution().kInversePairs(3, 0) << endl;
	cout << "K Inverse Pairs Array (n = 3, k = 1): " << Solution().kInversePairs(3, 1) << endl;
}
