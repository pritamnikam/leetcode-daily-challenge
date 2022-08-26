/*
658. Find K Closest Elements
https://leetcode.com/problems/find-k-closest-elements/

Given a sorted integer array arr, two integers k and x, return the k closest integers to x in the array. 
The result should also be sorted in ascending order.

An integer a is closer to x than an integer b if:

|a - x| < |b - x|, or
|a - x| == |b - x| and a < b


Example 1:

Input: arr = [1,2,3,4,5], k = 4, x = 3
Output: [1,2,3,4]
Example 2:

Input: arr = [1,2,3,4,5], k = 4, x = -1
Output: [1,2,3,4]


Constraints:

1 <= k <= arr.length
1 <= arr.length <= 104
arr is sorted in ascending order.
-104 <= arr[i], x <= 104

*/

using namespace std;

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>

namespace {
	class Solution {
	public:
		vector<int> findClosestElements(vector<int>& arr, int k, int x) {
			priority_queue<pair<int, int>> maxHeap;
			for (int num : arr) {
				maxHeap.push({ abs(num - x), num });
				if (maxHeap.size() > k)
					maxHeap.pop();
			}

			vector<int> result;
			while (!maxHeap.empty()) {
				result.push_back(maxHeap.top().second);
				maxHeap.pop();
			}

			sort(result.begin(), result.end());
			return result;
		}
	};
}

void testFindClosestElements() {
	vector<int> arr = { 1, 2, 3, 4, 5 };
	int k = 4, x = 3;
	vector<int> ans = Solution().findClosestElements(arr, k, x);

	x = -1;
	ans = Solution().findClosestElements(arr, k, x);
}