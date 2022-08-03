/*
Kth Largest Element in an Array

Given an integer array nums and an integer k, return the kth largest element in the array.

Note that it is the kth largest element in the sorted order, not the kth distinct element.

Example 1:

Input: nums = [3,2,1,5,6,4], k = 2
Output: 5
Example 2:

Input: nums = [3,2,3,1,2,4,5,5,6], k = 4
Output: 4


Constraints:

1 <= k <= nums.length <= 104
-104 <= nums[i] <= 104

*/

using namespace std;

#include <vector>
#include <queue>

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        if (nums.size() < k)
            return -1;

        priority_queue<int, vector<int>, greater<int>> minHeap;
        for (int n : nums) {
            minHeap.push(n);
            if (minHeap.size() > k)
                minHeap.pop();
        }

        return minHeap.top();
    }
}