// 1829. Maximum XOR for Each Query
// https://leetcode.com/problems/maximum-xor-for-each-query/

class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int xorProduct = 0;
        for (int i = 0; i < nums.size(); i++) {
            xorProduct = xorProduct ^ nums[i];
        }

        vector<int> ans(nums.size(), 0);
        int mask = (1 << maximumBit) - 1;

        for (int i = 0; i < nums.size(); i++) {
            ans[i] = xorProduct ^ mask;
            xorProduct = xorProduct ^ nums[nums.size() - 1 - i];
        }
        return ans;
    }
};
