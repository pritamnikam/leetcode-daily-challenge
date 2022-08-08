/*
300. Longest Increasing Subsequence
https://leetcode.com/problems/longest-increasing-subsequence/

Given an integer array nums, return the length of the longest strictly increasing subsequence.
A subsequence is a sequence that can be derived from an array by deleting some or no elements 
without changing the order of the remaining elements. For example, [3,6,2,7] is a subsequence 
of the array [0,3,1,6,2,2,7].

Example 1:
Input: nums = [10,9,2,5,3,7,101,18]
Output: 4
Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4.

Example 2:
Input: nums = [0,1,0,3,2,3]
Output: 4

Example 3:
Input: nums = [7,7,7,7,7,7,7]
Output: 1

Constraints:
1 <= nums.length <= 2500
-104 <= nums[i] <= 104

Follow up: Can you come up with an algorithm that runs in O(n log(n)) time complexity?
*/
using namespace std;

#include <iostream>
#include <vector>

namespace {
	class Solution {
	public:
		int lengthOfLIS(vector<int>& nums) {
			int n = nums.size();
			vector<int> dp(n, 1);
			int answer = 0;
			for (int i = 1; i < n; ++i) {
				for (int j = 0; j < i; ++j) {
					if (nums[i] > nums[j] && dp[i] <= dp[j]) {
						dp[i] = max(dp[i], 1 + dp[j]);
						answer = max(answer, dp[i]);
					}
				}
			}
			return answer;
		}
	};
}  // namespace


void testLengthOfLIS() {
	vector<int> nums = { 10, 9, 2, 5, 3, 7, 101, 18 };
	cout << "Longest Increasing Subsequence: " << Solution().lengthOfLIS(nums) << endl;

	nums = { 0, 1, 0, 3, 2, 3 };
	cout << "Longest Increasing Subsequence: " << Solution().lengthOfLIS(nums) << endl;
}
