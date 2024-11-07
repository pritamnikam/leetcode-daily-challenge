// 2275. Largest Combination with Bitwise and Greater than Zero
// https://leetcode.com/problems/largest-combination-with-bitwise-and-greater-than-zero/

class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        // Variable to track the maximum count of set bits.
        int maxCount = 0;
        for (int i = 0; i < 24; i++) {
            // Count of number with the i-th bit set
            int count = 0;
            for (int num: candidates) {
                // Check if the ith bit is set.
                if ((num & (1 << i)) != 0) {
                    count++;
                }
            }
            // Update the maximum count
            maxCount = max(maxCount, count);
        }

        return maxCount;
    }
};
