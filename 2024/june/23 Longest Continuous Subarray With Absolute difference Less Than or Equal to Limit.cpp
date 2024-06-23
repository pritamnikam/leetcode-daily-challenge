// 1438. Longest Continious Subarray With Absolute diff Less Than or Equal to Limit
// https://leetcode.com/problems/longest-continuous-subarray-with-absolute-diff-less-than-or-equal-to-limit


class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        multiset<int> window;
        int left = 0, maxLength = 0;

        for (int right = 0; right < nums.size(); ++right) {
            window.insert(nums[right]);

            while(*window.rbegin() - *window.begin() > limit) {
                window.erase(window.find(nums[left]));
                ++left;
            }

            maxLength = max(maxLength, right - left + 1);
        }
        return maxLength;
    }
};
