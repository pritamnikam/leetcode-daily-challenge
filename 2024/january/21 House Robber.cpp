// 198. House Robber
// https://leetcode.com/problems/house-robber/description/

class Solution {
public:
    int rob(vector<int>& nums) {
        int include = 0, exclude = 0;
        for (int n: nums) {
            int newInclude = n + exclude;
            exclude = max(exclude, include);
            include = newInclude;
        }

        return max(include , exclude);
    }
};
