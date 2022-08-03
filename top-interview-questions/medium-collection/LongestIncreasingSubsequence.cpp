/*
Longest Increasing Subsequence

Given an integer array nums, return the length of the longest strictly increasing subsequence.

A subsequence is a sequence that can be derived from an array by deleting some or no elements without changing the order of the remaining elements. For example, [3,6,2,7] is a subsequence of the array [0,3,1,6,2,2,7].



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

#include <vector>

class Solution {
    // Binary search (note boundaries in the caller)
    int CeilIndex(std::vector<int>& v, int l, int r, int key) {
        while (r - l > 1) {
            int m = l + (r - l) / 2;
            if (v[m] >= key)
                r = m;
            else
                l = m;
        }

        return r;
    }

public:
    int lengthOfLIS(vector<int>& v) {
        if (v.size() == 0)
            return 0;

        std::vector<int> tail(v.size(), 0);
        int length = 1; // always points empty slot in tail

        tail[0] = v[0];
        for (size_t i = 1; i < v.size(); i++) {

            // new smallest value
            if (v[i] < tail[0])
                tail[0] = v[i];

            // v[i] extends largest subsequence
            else if (v[i] > tail[length - 1])
                tail[length++] = v[i];

            // v[i] will become end candidate of an existing
            // subsequence or Throw away larger elements in all
            // LIS, to make room for upcoming greater elements
            // than v[i] (and also, v[i] would have already
            // appeared in one of LIS, identify the location
            // and replace it)
            else
                tail[CeilIndex(tail, -1, length - 1, v[i])] = v[i];
        }

        return length;
    }
};