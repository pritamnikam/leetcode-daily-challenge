/*
1493. Longest Subarray of 1's After Deleting One Element
https://leetcode.com/problems/longest-subarray-of-1s-after-deleting-one-element

Given a binary array nums, you should delete one element from it.

Return the size of the longest non-empty subarray containing only 1's in the resulting array. Return 0 if there is no such subarray.

Example 1:
Input: nums = [1,1,0,1]
Output: 3
Explanation: After deleting the number in position 2, [1,1,1] contains 3 numbers with value of 1's.

Example 2:
Input: nums = [0,1,1,1,0,1,1,0,1]
Output: 5
Explanation: After deleting the number in position 4, [0,1,1,1,1,1,0,1] longest subarray with value of 1's is [1,1,1,1,1].

Example 3:
Input: nums = [1,1,1]
Output: 2
Explanation: You must delete one element.

Constraints:
1 <= nums.length <= 105
nums[i] is either 0 or 1.

*/

using namespace std;

#include <iostream>
#include <vector>

namespace {
	class Solution {
	public:
		int longestSubarray(vector<int>& nums) {
			// Number of zero's in the window.
			int zeroCount = 0;
			int longestWindow = 0;

			// Left end of the window.
			int start = 0;

			for (int i = 0; i < nums.size(); i++) {
				zeroCount += (nums[i] == 0);

				// Shrink the window until the zero counts come under the limit.
				while (zeroCount > 1) {
					zeroCount -= (nums[start] == 0);
					start++;
				}

				longestWindow = max(longestWindow, i - start);
			}

			return longestWindow;
		}
	};
}
