/*
646. Maximum Length of Pair Chain
https://leetcode.com/problems/maximum-length-of-pair-chain/

You are given an array of n pairs pairs where pairs[i] = [lefti, righti] and lefti < righti.

A pair p2 = [c, d] follows a pair p1 = [a, b] if b < c. A chain of pairs can be formed in this fashion.

Return the length longest chain which can be formed.

You do not need to use up all the given intervals. You can select pairs in any order.

Example 1:
Input: pairs = [[1,2],[2,3],[3,4]]
Output: 2
Explanation: The longest chain is [1,2] -> [3,4].

Example 2:
Input: pairs = [[1,2],[7,8],[4,5]]

Output: 3
Explanation: The longest chain is [1,2] -> [4,5] -> [7,8].


Constraints:
n == pairs.length
1 <= n <= 1000
-1000 <= lefti < righti <= 1000
*/

using namespace std;

#include <iostream>
#include <vector>
#include <algorithm>

namespace{
    class Solution {
    public:
        int findLongestChain(vector<vector<int>>& pairs) {
            // Sort pairs in ascending order based on the second element.
            sort(pairs.begin(), pairs.end(),
                [](const vector<int>& a, const vector<int>& b) { return a[1] < b[1]; });
            int curr = INT_MIN, ans = 0;

            for (const auto& pair : pairs) {
                if (pair[0] > curr) {
                    ans++;
                    curr = pair[1];
                }
            }
            return ans;
        }

        int findLongestChain1(vector<vector<int>>& pairs) {
            sort(pairs.begin(), pairs.end());
            vector<vector<int>>dp(pairs.size(), vector<int>(2010, -1));
            return help(0, pairs, -1001, dp);
        }

    private:
        int help(int i, vector<vector<int>>& pairs, int mx, vector<vector<int>>& dp) {
            if (i == pairs.size()) 
                return 0;
            
            if (dp[i][mx + 1001] != -1)
                return dp[i][mx + 1001];
            
            int ans = help(i + 1, pairs, mx, dp);
            if (pairs[i][0] > mx) {
                ans = max(ans, 1 + help(i + 1, pairs, pairs[i][1], dp));
            }
            return  dp[i][mx + 1001] = ans;
        }
    };
} // namespace
