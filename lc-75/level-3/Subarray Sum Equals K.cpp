/*
560. Subarray Sum Equals K
https://leetcode.com/problems/subarray-sum-equals-k/

Given an array of integers nums and an integer k, 
return the total number of subarrays whose sum equals to k.

A subarray is a contiguous non-empty sequence of elements within an array.

Example 1:
Input: nums = [1,1,1], k = 2
Output: 2

Example 2:
Input: nums = [1,2,3], k = 3
Output: 2

Constraints:
1 <= nums.length <= 2 * 104
-1000 <= nums[i] <= 1000
-107 <= k <= 107

*/

using namespace std;

#include <iostream>
#include <vector>
#include <unordered_map>

namespace {
	class Solution {
	public:
		int subarraySum(vector<int>& nums, int k) {
			unordered_map<int, int> prefixSumFreq;

			int count = 0;
			int currentSum = 0;
			for (int n: nums) {
				// prefix sum
				currentSum += n;

				// situation 1:  
				// continuous subarray starts 
				// from the beginning of the array
				if (currentSum == k) ++count;

				// situation 2:
				// number of times the curr_sum − k has occured already, 
				// determines the number of times a subarray with sum k 
				// has occured upto the current index
				if (prefixSumFreq.count(currentSum - k)) {
					count += prefixSumFreq[currentSum - k];
				}

				// add the current sum
				prefixSumFreq[currentSum] += 1;
			}

			return count;
		}
	};
}

void testSubarraySumEqualsK() {
	// Input: nums = [1,1,1], k = 2
	// Output: 2

	vector<int> nums = { 1,1,1 };
	int k = 2;
	cout << "Subarray Sum Equals K: " << Solution().subarraySum(nums, k) << endl;
}