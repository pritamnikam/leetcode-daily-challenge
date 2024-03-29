// 2962. Count Subarrays Where Max Element Appears At Least K Times
// https://leetcode.com/problems/count-subarrays-where-max-element-appears-at-least-k-times/

class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int maxElement = *max_element(nums.begin(), nums.end());
        vector<int> indexesOfMaxElement;
        long long answer = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == maxElement) {
                indexesOfMaxElement.push_back(i);
            }

            int freq = indexesOfMaxElement.size();
            if (freq >= k) {
                answer += indexesOfMaxElement[freq - k] + 1;
            }
        }

        return answer;
    }
};
