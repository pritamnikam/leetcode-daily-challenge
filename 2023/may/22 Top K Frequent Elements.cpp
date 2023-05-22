/*
347. Top K Frequent Elements
https://leetcode.com/problems/top-k-frequent-elements/description/

Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.



Example 1:

Input: nums = [1,1,1,2,2,3], k = 2
Output: [1,2]
Example 2:

Input: nums = [1], k = 1
Output: [1]


Constraints:

1 <= nums.length <= 105
-104 <= nums[i] <= 104
k is in the range [1, the number of unique elements in the array].
It is guaranteed that the answer is unique.


Follow up: Your algorithm's time complexity must be better than O(n log n), where n is the array's size.


*/

using namespace std;

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

namespace {
	typedef pair<int, int> pi;
	typedef pair<int, pi> ppi;

	class Solution {
	public:
		vector<int> topKFrequent(vector<int>& nums, int k) {
			unordered_map<int, int> numberFreqMap;
			for (int n : nums)
				numberFreqMap[n]++;

			// {freq, num}
			priority_queue<pi, vector<pi>, greater<pi>> minHeap;
			for (auto& it : numberFreqMap) {
				minHeap.push({ it.second, it.first });
				if (minHeap.size() > k) minHeap.pop();
			}

			vector<int> answer;
			while (!minHeap.empty()) {
				answer.push_back(minHeap.top().second);
				minHeap.pop();
			}

			return answer;
		}
	};
}
