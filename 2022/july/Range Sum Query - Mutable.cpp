/*
307. Range Sum Query - Mutable
https://leetcode.com/problems/range-sum-query-mutable/

Given an integer array nums, handle multiple queries of the following types:

Update the value of an element in nums.
Calculate the sum of the elements of nums between indices left and right inclusive where left <= right.
Implement the NumArray class:

NumArray(int[] nums) Initializes the object with the integer array nums.
void update(int index, int val) Updates the value of nums[index] to be val.
int sumRange(int left, int right) Returns the sum of the elements of nums between indices left and right inclusive (i.e. nums[left] + nums[left + 1] + ... + nums[right]).

Example 1:

Input
["NumArray", "sumRange", "update", "sumRange"]
[[[1, 3, 5]], [0, 2], [1, 2], [0, 2]]
Output
[null, 9, null, 8]

Explanation
NumArray numArray = new NumArray([1, 3, 5]);
numArray.sumRange(0, 2); // return 1 + 3 + 5 = 9
numArray.update(1, 2);   // nums = [1, 2, 5]
numArray.sumRange(0, 2); // return 1 + 2 + 5 = 8


Constraints:

1 <= nums.length <= 3 * 104
-100 <= nums[i] <= 100
0 <= index < nums.length
-100 <= val <= 100
0 <= left <= right < nums.length
At most 3 * 104 calls will be made to update and sumRange.
*/

using namespace std;

#include <iostream>
#include <vector>

namespace {
	class NumArray {
		int n;
		vector<int> arr;
		vector<int> bit;


	private:
		void build(int key, int value) {
			key++;
			while (key <= n) {
				bit[key] += value;
				key += (key & -key);
			}
		}

		int query(int key) {
			int sum = 0;
			while (key > 0) {
				sum += bit[key];
				key -= (key & -key);
			}

			return sum;
		}

	public:
		NumArray(vector<int>& nums) {
			n = nums.size();
			bit = vector<int>(n + 1, 0);
			arr = nums;

			for (int i = 0; i < n; ++i) {
				build(i, nums[i]);
			}
		}


		void update(int index, int val) {
			int diff = val - arr[index];
			build(index, diff);
			arr[index] = val;
		}

		int sumRange(int left, int right) {
			return query(right + 1) - query(left);
		}
	};
}