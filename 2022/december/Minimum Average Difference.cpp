/*
2256. Minimum Average Difference
https://leetcode.com/problems/minimum-average-difference/

You are given a 0-indexed integer array nums of length n.

The average difference of the index i is the absolute difference between the average of the first i + 1 elements of nums
and the average of the last n - i - 1 elements. Both averages should be rounded down to the nearest integer.

Return the index with the minimum average difference. If there are multiple such indices, return the smallest one.

Note:
The absolute difference of two numbers is the absolute value of their difference.
The average of n elements is the sum of the n elements divided (integer division) by n.
The average of 0 elements is considered to be 0.


Example 1:

Input: nums = [2,5,3,9,5,3]
Output: 3
Explanation:
- The average difference of index 0 is: |2 / 1 - (5 + 3 + 9 + 5 + 3) / 5| = |2 / 1 - 25 / 5| = |2 - 5| = 3.
- The average difference of index 1 is: |(2 + 5) / 2 - (3 + 9 + 5 + 3) / 4| = |7 / 2 - 20 / 4| = |3 - 5| = 2.
- The average difference of index 2 is: |(2 + 5 + 3) / 3 - (9 + 5 + 3) / 3| = |10 / 3 - 17 / 3| = |3 - 5| = 2.
- The average difference of index 3 is: |(2 + 5 + 3 + 9) / 4 - (5 + 3) / 2| = |19 / 4 - 8 / 2| = |4 - 4| = 0.
- The average difference of index 4 is: |(2 + 5 + 3 + 9 + 5) / 5 - 3 / 1| = |24 / 5 - 3 / 1| = |4 - 3| = 1.
- The average difference of index 5 is: |(2 + 5 + 3 + 9 + 5 + 3) / 6 - 0| = |27 / 6 - 0| = |4 - 0| = 4.
The average difference of index 3 is the minimum average difference so return 3.
Example 2:

Input: nums = [0]
Output: 0
Explanation:
The only index is 0 so return 0.
The average difference of index 0 is: |0 / 1 - 0| = |0 - 0| = 0.


Constraints:

1 <= nums.length <= 105
0 <= nums[i] <= 105

*/

using namespace std;

#include <iostream>
#include <vector>

namespace {
    class Solution {
    public:
        int minimumAverageDifference(vector<int>& nums) {
            int n = int(nums.size());
            int ans = -1;
            int minAvgDiff = numeric_limits<int>::max();

            // Generate prefix and suffix sum arrays.
            vector<long long> prefixSum(n + 1);
            vector<long long> suffixSum(n + 1);

            for (int index = 0; index < n; ++index) {
                prefixSum[index + 1] = prefixSum[index] + nums[index];
            }

            for (int index = n - 1; index >= 0; --index) {
                suffixSum[index] = suffixSum[index + 1] + nums[index];
            }

            for (int index = 0; index < n; ++index) {
                // Calculate average of left part of array, index 0 to i.
                long long leftPartAverage = prefixSum[index + 1];
                leftPartAverage /= (index + 1);

                // Calculate average of right part of array, index i+1 to n-1.
                long long rightPartAverage = suffixSum[index + 1];
                // If right part have 0 elements, then we don't divide by 0.
                if (index != n - 1) {
                    rightPartAverage /= (n - index - 1);
                }

                int currDifference = int(abs(leftPartAverage - rightPartAverage));
                // If current difference of averages is smaller,
                // then current index can be our answer.
                if (currDifference < minAvgDiff) {
                    minAvgDiff = currDifference;
                    ans = index;
                }
            }

            return ans;
        }
    };
}  // namespace

void testMinimumAverageDifference() {
    // Input: nums = [2,5,3,9,5,3], Output: 3
    vector<int>  nums = { 2, 5, 3, 9, 5, 3 };
    cout << "Minimum Average Difference: " << Solution().minimumAverageDifference(nums) << endl;

    // Input: nums = [0], Output: 0
    nums = { 0 };
    cout << "Minimum Average Difference: " << Solution().minimumAverageDifference(nums) << endl;
}
