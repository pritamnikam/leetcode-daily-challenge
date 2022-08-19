/*
659. Split Array into Consecutive Subsequences
https://leetcode.com/problems/split-array-into-consecutive-subsequences/

You are given an integer array nums that is sorted in non-decreasing order.

Determine if it is possible to split nums into one or more subsequences such that both of the following conditions are true:

Each subsequence is a consecutive increasing sequence (i.e. each integer is exactly one more than the previous integer).
All subsequences have a length of 3 or more.
Return true if you can split nums according to the above conditions, or false otherwise.

A subsequence of an array is a new array that is formed from the original array by deleting some (can be none) of the elements without disturbing the relative positions of the remaining elements. (i.e., [1,3,5] is a subsequence of [1,2,3,4,5] while [1,3,2] is not).



Example 1:

Input: nums = [1,2,3,3,4,5]
Output: true
Explanation: nums can be split into the following subsequences:
[1,2,3,3,4,5] --> 1, 2, 3
[1,2,3,3,4,5] --> 3, 4, 5
Example 2:

Input: nums = [1,2,3,3,4,4,5,5]
Output: true
Explanation: nums can be split into the following subsequences:
[1,2,3,3,4,4,5,5] --> 1, 2, 3, 4, 5
[1,2,3,3,4,4,5,5] --> 3, 4, 5
Example 3:

Input: nums = [1,2,3,4,4,5]
Output: false
Explanation: It is impossible to split nums into consecutive increasing subsequences of length 3 or more.


Constraints:

1 <= nums.length <= 104
-1000 <= nums[i] <= 1000
nums is sorted in non-decreasing order.

*/


using namespace std;

#include <iostream>
#include <vector>
#include <unordered_map>

namespace {
	class Solution {
	public:
		bool isPossible(vector<int>& nums) {
			unordered_map<int, int> counts, tails;

			for (int n : nums) counts[n]++;

			for (int n : nums) {
				// all the |n| are already placed
				if (!counts[n]) continue;

				counts[n]--;

				// When we meet number n, try to put it to the tail of one of found subsequences tailed by n-1
				if (tails[n - 1] > 0) {
					tails[n - 1]--;
					tails[n]++;
				}

				// If we can't, it will cost one n+1 and one n+2 later to generate a new sequence.
				else if (counts[n + 1] && counts[n + 2]) {
					counts[n + 1]--;
					counts[n + 2]--;
					tails[n + 2]++;
				}

				else {
					return false;
				}
			}

			return true;
		}
	};
}

void testSplitArrayIntoConsecutiveSubsequences() {
	vector<int> nums = { 1, 2, 3, 3, 4, 5 };
	cout << "Split Array into Consecutive Subsequences: " << Solution().isPossible(nums) << endl;


	nums = { 1,2,3,3,4,4,5,5 };
	cout << "Split Array into Consecutive Subsequences: " << Solution().isPossible(nums) << endl;

	nums = { 1, 2, 3, 4, 4, 5 };
	cout << "Split Array into Consecutive Subsequences: " << Solution().isPossible(nums) << endl;
}