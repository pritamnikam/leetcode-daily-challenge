// 2009. Minimum Number of Operations to Make Array Continous
// https://leetcode.com/problems/minimum-number-of-operations-to-make-array-continuous/

using namespace std;

#include <iostream>
#include <vector>
#include <algorithm>

namespace {class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int ans = n;
        
        // std::set automatically sorts
        set<int> unique(nums.begin(), nums.end());
        vector<int> newNums;
        for (int num: unique) {
            newNums.push_back(num);
        }
        
        for (int i = 0; i < newNums.size(); i++) {
            int left = newNums[i];
            int right = left + n - 1;
            int j = upper_bound(newNums.begin(), newNums.end(), right) - newNums.begin();
            int count = j - i;
            ans = min(ans, n - count);
        }
        
        return ans;
    }
};
  
}
