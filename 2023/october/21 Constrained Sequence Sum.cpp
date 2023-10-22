// 1425. Constrained Sequence Sum
// https://leetcode.com/problems/constrained-subsequence-sum

using namespace std;

#include <iostream>
#include <vector>
#include <deque>

namespace {

class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        int n = nums.size();
        deque<int> queue;
        vector<int> dp(n);

        for (int i = 0; i < n; i++) {
            if (!queue.empty() && i - queue.front() > k) {
                queue.pop_front();
            }

            dp[i] = (!queue.empty() ? dp[queue.front()] : 0) + nums[i];
            while (!queue.empty() && dp[queue.back()] < dp[i]) {
                queue.pop_back();
            }

            if (dp[i] > 0) {
                queue.push_back(i);
            }
        }

        return *max_element(dp.begin(), dp.end());
    }
};

}
