// 2958. Length of Subarray With At Most k Frequency
// https://leetcode.com/problems/length-of-longest-subarray-with-at-most-k-frequency/

class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> freq;
        int start = 0;
        int charWithFreqOverK = 0;

        for (int end = 0; end < n; end++) {
            freq[nums[end]]++;

            if (freq[nums[end]] == k + 1) {
                charWithFreqOverK++;
            }

            if (charWithFreqOverK > 0) {
                freq[nums[start]]--;
                if (freq[nums[start]] == k) {
                    charWithFreqOverK--;
                }
                start++;
            }
        }

        return n - start;
    }
};
