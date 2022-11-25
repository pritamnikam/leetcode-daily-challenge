/*
907. Sum of Subarray Minimums
https://leetcode.com/problems/sum-of-subarray-minimums/

Given an array of integers arr, find the sum of min(b), 
where b ranges over every (contiguous) subarray of arr. 

Since the answer may be large, return the answer modulo 109 + 7.

Example 1:
Input: arr = [3,1,2,4]
Output: 17
Explanation:
Subarrays are [3], [1], [2], [4], [3,1], [1,2], [2,4], [3,1,2], [1,2,4], [3,1,2,4].
Minimums are 3, 1, 2, 4, 1, 1, 2, 1, 1, 1.
Sum is 17.

Example 2:
Input: arr = [11,81,94,43,3]
Output: 444


Constraints:
1 <= arr.length <= 3 * 104
1 <= arr[i] <= 3 * 104

*/

using namespace std;

#include <iostream>
#include <vector>
#include <stack>

namespace {
    class Solution {
    public:
        // brute force
        /*
        * we have been focusing on the range first. Once we have a range, 
        * we look for the minimum element in the range. 
        * Generating these ranges is the most time-consuming part of the algorithm.
        */
        int sumSubarrayMins1(vector<int>& arr) {
            int runningTotal = 0;
            for (int i = 0; i < arr.size(); ++i) {
                int minimumElement = arr[i];
                for (int j = i; j < arr.size(); ++j) {
                    minimumElement = min(minimumElement, arr[j]);
                    runningTotal += minimumElement;
                }
            }

            return runningTotal;
        }


        // Finding the previous smaller and the next smaller elements with a monotonic stack
        /*
            How much the element 3 contributes to the final answer?
            It is 3*(4*3).
            What is the final answer?
            Denote by left[i] the distance between element A[i] and its PLE.
            Denote by right[i] the distance between element A[i] and its NLE.

            The final answer is,
            sum(A[i]*left[i]*right[i] )
        */

        int sumSubarrayMins(vector<int>& arr) {
            // left is for the distance to previous less element
            // right is for the distance to next less element
            vector<int> left(arr.size()),
                        right(arr.size());

            //initialize
            for (int i = 0; i < arr.size(); i++)
                left[i] = i + 1;

            for (int i = 0; i < arr.size(); i++)
                right[i] = arr.size() - i;

            stack<pair<int, int>> in_stk_p,
                in_stk_n;
            for (int i = 0; i < arr.size(); i++) {
                // for previous less
                while (!in_stk_p.empty()
                    && in_stk_p.top().first > arr[i]) {
                    in_stk_p.pop();
                }

                left[i] = in_stk_p.empty()
                    ? i + 1
                    : i - in_stk_p.top().second;

                in_stk_p.push({ arr[i],i });

                // for next less
                while (!in_stk_n.empty()
                    && in_stk_n.top().first > arr[i]) {
                    auto x = in_stk_n.top();
                    in_stk_n.pop();

                    right[x.second] = i - x.second;
                }

                in_stk_n.push({ arr[i], i });
            }

            long long ans = 0,
                      mod = 1e9 + 7;
            for (int i = 0; i < arr.size(); i++) {
                ans = (ans +
                    ((long long)arr[i]
                        * (long long)left[i]
                        * (long long)right[i])) % mod;
            }
            return (int)ans;
        }
    };
} // namespace

void testSumOfSubarrayMinimums() {
    /*
        Input: arr = [3,1,2,4], Output: 17
    */
    vector<int> arr = {3, 1, 2, 4};
    cout << "Sum of Subarray Minimums: " << Solution().sumSubarrayMins(arr) << endl;

    /*
        Input: arr = [11,81,94,43,3], Output: 444
    */

    arr = { 11,81,94,43,3 };
    cout << "Sum of Subarray Minimums: " << Solution().sumSubarrayMins(arr) << endl;
}
