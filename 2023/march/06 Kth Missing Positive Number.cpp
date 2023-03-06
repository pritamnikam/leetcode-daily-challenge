/*
1539. Kth Missing Positive Number
https://leetcode.com/problems/kth-missing-positive-number/

Given an array arr of positive integers sorted in a strictly increasing order, and an integer k.
Return the kth positive integer that is missing from this array.

Example 1:
Input: arr = [2,3,4,7,11], k = 5
Output: 9
Explanation: The missing positive integers are [1,5,6,8,9,10,12,13,...]. The 5th missing positive integer is 9.

Example 2:
Input: arr = [1,2,3,4], k = 2
Output: 6
Explanation: The missing positive integers are [5,6,7,...]. The 2nd missing positive integer is 6.

Constraints:
1 <= arr.length <= 1000
1 <= arr[i] <= 1000
1 <= k <= 1000
arr[i] < arr[j] for 1 <= i < j <= arr.length


Follow up:
Could you solve this problem in less than O(n) complexity?

*/


#include <iostream>
#include <vector>

using namespace std;

namespace {
	class Solution {
    public:
        // binary search
        // The number of positive integers which are missing before the arr[idx] is equal to arr[idx] - idx - 1.

        /*
            Now we have everything to proceed with the classical binary search algorithm:

            Choose the pivot index in the middle of the array.

            1. If the number of positive integers which are missing before arr[pivot] is less than k - continue to search on the right side of the array.

            2. Otherwise, continue to search on the left side.
        */

        int findKthPositive(vector<int>& arr, int k) {
            int left = 0, 
                right = arr.size() - 1;

            while (left <= right) {
                int mid = left + (right - left) / 2;
                if (arr[mid] - (mid + 1) < k) {
                    // move right
                    left = mid + 1;
                }
                else {
                    // move left
                    right = mid - 1;
                }
            }

            // At the end of the loop, left = right + 1,
            // and the kth missing is in-between arr[right] and arr[left].
            //
            // The number of integers missing before arr[right] is: arr[right] - right - 1
            // the number to return is:
            // arr[right] + k - (arr[right] - right - 1) => k + right + 1 => k + left
            return k + left;
        }
	};
}

void testKthMissingPositiveNumber() {
    // Input: arr = [2,3,4,7,11], k = 5 | Output: 9
    vector<int> arr = { 2,3,4,7,11 }; int k = 5;
    cout << "Kth Missing Positive Number: " << Solution().findKthPositive(arr, k) << endl;
}
