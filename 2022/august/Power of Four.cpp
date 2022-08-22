/*
342. Power of Four
https://leetcode.com/problems/power-of-four/

Given an integer n, return true if it is a power of four. Otherwise, return false.

An integer n is a power of four, if there exists an integer x such that n == 4x.



Example 1:

Input: n = 16
Output: true
Example 2:

Input: n = 5
Output: false
Example 3:

Input: n = 1
Output: true


Constraints:

-231 <= n <= 231 - 1

*/

using namespace std;
#include <iostream>
namespace {
	class Solution {
	public:
		bool isPowerOfFour(int num) {
			return num > 0 
				&& (num & (num - 1)) == 0 
				&& (num % 3) == 1;
		}
	};
}


void testIsPowerOfFour() {
	cout << Solution().isPowerOfFour(16) << endl;
	cout << Solution().isPowerOfFour(5) << endl;
	cout << Solution().isPowerOfFour(1) << endl;
}
