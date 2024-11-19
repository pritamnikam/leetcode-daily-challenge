// 2461 maximum-sum-of-distinct-subarrays-with-length-k
// https://leetcode.com/problems/maximum-sum-of-distinct-subarrays-with-length-k/

class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long ans = 0;
        long long currentSum = 0;
        int begin = 0;
        int end  = 0;

        unordered_map<int, int> numToIndex;

        while (end  < nums.size()) {
            int curNum = nums[end];
            int lastOccurance = numToIndex.count(curNum) ? numToIndex[curNum] : -1;

            while (begin <= lastOccurance || end - begin + 1 > k) {
                currentSum -= nums[begin];
                begin++;
            }

            numToIndex[curNum] = end;
            currentSum += nums[end];
            if (end - begin + 1 == k) {
                ans = max(ans, currentSum);
            }
            end++;
        }
        return ans;
    }
};
