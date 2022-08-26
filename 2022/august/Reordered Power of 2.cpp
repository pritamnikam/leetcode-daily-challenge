/*
Reordered Power of 2
https://leetcode.com/problems/reordered-power-of-2/

You are given an integer n. We reorder the digits in any order (including the original order) such that the leading digit is not zero.

Return true if and only if we can do this so that the resulting number is a power of two.

Example 1:
Input: n = 1
Output: true

Example 2:
Input: n = 10
Output: false

Constraints:
1 <= n <= 10^9

*/

using namespace std;

#include <vector>
#include <iostream>

namespace {
	class Solution {
	public:
		bool reorderedPowerOf2(int n) {
			vector<int> A = count(n);
			for (int i = 0; i < 31; ++i) {
				if (A == count(1 << i)) {
					return true;
				}
			}
			return false;
		}

	private:
		vector<int> count(int N) {
			vector<int> ans(10, 0);
			while (N > 0) {
				ans[N % 10]++;
				N /= 10;
			}

			return ans;
		}
	};
}

void testReorderedPowerOf2() {
	cout << "Reordered Power of 2: " << Solution().reorderedPowerOf2(128) << endl;
	cout << "Reordered Power of 112223334: " << Solution().reorderedPowerOf2(128) << endl;
}