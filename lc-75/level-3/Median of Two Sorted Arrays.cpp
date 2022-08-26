/*
4. Median of Two Sorted Arrays
https://leetcode.com/problems/median-of-two-sorted-arrays/

Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.

The overall run time complexity should be O(log (m+n)).



Example 1:

Input: nums1 = [1,3], nums2 = [2]
Output: 2.00000
Explanation: merged array = [1,2,3] and median is 2.
Example 2:

Input: nums1 = [1,2], nums2 = [3,4]
Output: 2.50000
Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.


Constraints:

nums1.length == m
nums2.length == n
0 <= m <= 1000
0 <= n <= 1000
1 <= m + n <= 2000
-106 <= nums1[i], nums2[i] <= 106


*/

using namespace std;

#include <iostream>
#include <vector>

namespace {
    class Solution {

    public:
        double findMedianSortedArrays(vector<int>& A, vector<int>& B) {
            long n = A.size(), m = B.size(), t = (n + m + 1) / 2;
            if (n > m)
                return findMedianSortedArrays(B, A);

            if (n == 0)
                return m % 2 == 0 ? (double)(B[m / 2 - 1] + B[m / 2]) / 2 : B[m / 2];

            if (m == 0)
                return n % 2 == 0 ? (double)(A[n / 2 - 1] + A[n / 2]) / 2 : A[n / 2];

            long left = 0, right = n;
            while (left <= right) {
                long partitionA = left + (right - left) / 2;
                long partitionB = t - double(partitionA);      // partitionA + partitionB = (n+m+1)/2

                //if partitionA is 0 then take INT_MIN for maxLeftA (nothing is left in the left of partition)
                double maxLeftA = INT_MIN;
                if (partitionA > 0) {
                    maxLeftA = A[partitionA - 1];
                }

                // if partitionA is n then take INT_MAX for minRightA (nothing is left in the right of partition)
                double minRightA = INT_MAX;
                if (partitionA < n) {
                    minRightA = A[partitionA];
                }

                // Similarly for maxLeftB and minrightB
                double maxLeftB = INT_MIN;
                if (partitionB > 0) {
                    maxLeftB = B[partitionB - 1];
                }

                double minRightB = INT_MAX;
                if (partitionB < m) {
                    minRightB = B[partitionB];
                }


                // check weather it's a perfect partition or not
                if (maxLeftA <= minRightB && maxLeftB <= minRightA) {
                    // if the sorted merged array is of even lengt
                    if ((n + m) % 2 == 0) {
                        return (max(maxLeftA, maxLeftB) +
                            min(minRightA, minRightB)) / 2.0;
                    }
                    else {
                        return max(maxLeftA, maxLeftB);
                    }
                }

                // move left side.
                else if (maxLeftA > minRightB) {
                    right = partitionA - 1;
                }

                // move right side
                else {
                    left = partitionA + 1;
                }
            } // while

            // we can't find the median if input is invalid i.e., arrays are not sorted
            return 0.0;
        }
    };
}