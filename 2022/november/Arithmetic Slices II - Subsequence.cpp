/*
446. Arithmetic Slices II - Subsequence
https://leetcode.com/problems/arithmetic-slices-ii-subsequence/

Given an integer array nums, return the number of all the arithmetic subsequences of nums.

A sequence of numbers is called arithmetic if it consists of at least three elements and if the difference between any two consecutive elements is the same.

For example, [1, 3, 5, 7, 9], [7, 7, 7, 7], and [3, -1, -5, -9] are arithmetic sequences.
For example, [1, 1, 2, 5, 7] is not an arithmetic sequence.
A subsequence of an array is a sequence that can be formed by removing some elements (possibly none) of the array.

For example, [2,5,10] is a subsequence of [1,2,1,2,4,1,5,10].
The test cases are generated so that the answer fits in 32-bit integer.



Example 1:

Input: nums = [2,4,6,8,10]
Output: 7
Explanation: All arithmetic subsequence slices are:
[2,4,6]
[4,6,8]
[6,8,10]
[2,4,6,8]
[4,6,8,10]
[2,4,6,8,10]
[2,6,10]
Example 2:

Input: nums = [7,7,7,7,7]
Output: 16
Explanation: Any subsequence of this array is arithmetic.


Constraints:

1  <= nums.length <= 1000
-231 <= nums[i] <= 231 - 1

*/

#include <iostream>
#include <vector>
#include <map>

using namespace std;


#define LL long long

namespace {
    // Brute Force 
    class Solution1 {
    public:
        int n;
        int ans;
        void dfs(int dep, vector<int>& A, vector<LL> cur) {
            if (dep == n) {
                if (cur.size() < 3) {
                    return;
                }
                for (int i = 1; i < cur.size(); i++) {
                    if (cur[i] - cur[i - 1] != cur[1] - cur[0]) {
                        return;
                    }
                }
                ans++;
                return;
            }
            dfs(dep + 1, A, cur);
            cur.push_back(A[dep]);
            dfs(dep + 1, A, cur);
        }

        int numberOfArithmeticSlices(vector<int>& A) {
            n = A.size();
            ans = 0;
            vector<LL> cur;
            dfs(0, A, cur);
            return (int)ans;
        }
    };

    // Dynamic Programming 
    // f[i][d] denotes the number of weak arithmetic subsequences that ends with A[i] and its common difference is d.
    // for all j < i:
    //  f[i][A[i] - A[j]] += (f[j][A[i] - A[j]] + 1).
    class Solution {
    public:
        int numberOfArithmeticSlices(vector<int>& A) {
            int n = A.size();
            LL ans = 0;
            vector<map<LL, int>> cnt(n);
            for (int i = 1; i < n; i++) {
                for (int j = 0; j < i; j++) {
                    LL delta = (LL)A[i] - (LL)A[j];
                    int sum = 0;
                    if (cnt[j].find(delta) != cnt[j].end()) {
                        sum = cnt[j][delta];
                    }
                    cnt[i][delta] += sum + 1;
                    ans += sum;
                }
            }

            return (int)ans;
        }
    };
} // namespace

void testArithmeticSlicesIISubsequence() {
    /* 
        Input: nums = [2,4,6,8,10], Output: 7
    */
    vector<int> nums = { 2, 4, 6, 8, 10 };
    cout << "Arithmetic Slices II - Subsequence: " 
        << Solution().numberOfArithmeticSlices(nums) 
        << endl;
}
