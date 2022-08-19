/*
632. Smallest Range Covering Elements from K Lists
https://leetcode.com/problems/smallest-range-covering-elements-from-k-lists/

You have k lists of sorted integers in non-decreasing order. 
Find the smallest range that includes at least one number from each of the k lists.

We define the range [a, b] is smaller than range [c, d] if b - a < d - c or a < c if b - a == d - c.



Example 1:
Input: nums = [[4,10,15,24,26],[0,9,12,20],[5,18,22,30]]
Output: [20,24]

Explanation:
List 1: [4, 10, 15, 24,26], 24 is in range [20,24].
List 2: [0, 9, 12, 20], 20 is in range [20,24].
List 3: [5, 18, 22, 30], 22 is in range [20,24].
Example 2:

Input: nums = [[1,2,3],[1,2,3],[1,2,3]]
Output: [1,1]


Constraints:

nums.length == k
1 <= k <= 3500
1 <= nums[i].length <= 50
-105 <= nums[i][j] <= 105
nums[i] is sorted in non-decreasing order.


*/


using namespace std;

#include <iostream>
#include <vector>
#include <queue>

namespace {
    // data structure that hold mapping for number to array and it's index
    typedef pair<int, pair<int, int>> ppi;

    struct Compare {
        bool operator() (const ppi& a, const ppi& b) {
            return a.first > b.first;
        }
    };

    class Solution {
    public:
        vector<int> smallestRange(vector<vector<int>>& nums) {

            // mih-heap -> {number => {list-id, index}}
            priority_queue<ppi, vector<ppi>, Compare> minHeap;
            int curMaxNumber = INT_MIN;
            int rangeStart = 0;
            int rangeEnd = INT_MAX;

            for (int i = 0; i < nums.size(); ++i) {
                if (!nums[i].empty()) {
                    // {number => {list-id, index}}
                    minHeap.push({ nums[i][0], {i, 0} });
                    curMaxNumber = max(curMaxNumber, nums[i][0]);
                }
            }

            while (minHeap.size() == nums.size()) {
                ppi node = minHeap.top();
                minHeap.pop();

                if (rangeEnd - rangeStart > curMaxNumber - node.first) {
                    rangeEnd = curMaxNumber;
                    rangeStart = node.first;
                }

                // add next element in the same list
                node.second.second++;
                if (node.second.second < nums[node.second.first].size()) {
                    node.first = nums[node.second.first][node.second.second];
                    minHeap.push(node);

                    curMaxNumber = max(curMaxNumber, node.first);
                }
            }

            return vector<int>({ rangeStart, rangeEnd });
        }
    };
}

void testSmallestRangeCoveringElementsFromKLists() {
    vector<vector<int>> nums = { {4, 10, 15, 24, 26},{0, 9, 12, 20},{5, 18, 22, 30} };
    vector<int> output = Solution().smallestRange(nums);
}