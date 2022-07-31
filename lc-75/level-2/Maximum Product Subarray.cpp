/*
152. Maximum Product Subarray
https://leetcode.com/problems/maximum-product-subarray/


Given an integer array nums, find a contiguous non-empty subarray within the array that has the largest product, and return the product.

The test cases are generated so that the answer will fit in a 32-bit integer.

A subarray is a contiguous subsequence of the array.



Example 1:
Input: nums = [2,3,-2,4]
Output: 6
Explanation: [2,3] has the largest product 6.

Example 2:
Input: nums = [-2,0,-1]
Output: 0
Explanation: The result cannot be 2, because [-2,-1] is not a subarray.


Constraints:
1 <= nums.length <= 2 * 104
-10 <= nums[i] <= 10
The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.
*/


using namespace std;

#include <vector>
#include <iostream>

namespace {

    /*
Kaden's Algo.

solution:
1. maintain 2 variables: currentMin & currentMax, and init them to 1.
2. for every element in array, calculate the currentMin & currentMax by considering min or max of product to tht of prev values.
3. calculate the global max product
*/

    class Solution {
    public:
        int maxProduct(vector<int>& nums) {
            int currentMin = 1,
                currentMax = 1,
                maxProduct = INT_MIN;

            for (int element : nums) {
                int prevMax = currentMax,
                    prevMin = currentMin;

                currentMax = max({ element, element * prevMax, element * prevMin });
                currentMin = min({ element, element * prevMax, element * prevMin });
                maxProduct = max({ maxProduct, currentMax, currentMin });
            }

            return maxProduct;
        }
    };
}