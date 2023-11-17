// 1877. Minimize Maximum Pair Sum
// https://leetcode.com/problems/minimize-maximum-pair-sum-in-array

class Solution {
public:
    int minPairSum(vector<int>& nums) {
        // sort numbers in ascending order.
        sort(nums.begin(), nums.end());
      
        // sum up front and rear element from sorted list
        int maxSum = 0, n = nums.size() - 1;
        for (int i = 0; i <= n; i++) {
            maxSum = max(maxSum, nums[i] + nums[n - i]);
        }
      
        return maxSum;
    }
};
