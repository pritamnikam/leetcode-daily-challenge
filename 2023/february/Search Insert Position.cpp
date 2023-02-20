/*
35. Search Insert Position
https://leetcode.com/problems/search-insert-position

Given a sorted array of distinct integers and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You must write an algorithm with O(log n) runtime complexity.



Example 1:

Input: nums = [1,3,5,6], target = 5
Output: 2
Example 2:

Input: nums = [1,3,5,6], target = 2
Output: 1
Example 3:

Input: nums = [1,3,5,6], target = 7
Output: 4


Constraints:

1 <= nums.length <= 104
-104 <= nums[i] <= 104
nums contains distinct values sorted in ascending order.
-104 <= target <= 104

*/

using namespace std;

#include <iostream>
#include <vector>

namespace {
	class Solution {
	public:
		int searchInsert(vector<int>& nums, int target) {
            int lo = 0,
                hi = nums.size() - 1;

            while (lo <= hi) {
                int mid = lo + (hi - lo) / 2;
                if (target == nums[mid]) {
                    return mid;
                }
                else if (target < nums[mid]) {
                    hi = mid - 1;
                }
                else {
                    lo = mid + 1;
                }
            }

            return lo;
		}
	};
} // namespace

void testSearchInsertPosition() {
    // Input: nums = [1,3,5,6], target = 5
    // Output: 2

    vector<int>  nums = { 1, 3, 5, 6 };
    int target = 5;

    cout << "Search Insert Position: " << Solution().searchInsert(nums, target) << endl;
}
