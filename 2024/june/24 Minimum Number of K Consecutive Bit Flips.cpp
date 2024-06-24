// 995. Minimum Number of K Consecutive Bit Flips
// https://leetcode.com/problems/minimum-number-of-k-consecutive-bit-flips

class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int n = nums.size();
        deque<int> flipQueue;
        int flipped = 0;
        int result = 0;

        for (int i = 0; i < n; i++) {
            if (i >= k) {
                flipped ^= flipQueue.front();
                flipQueue.pop_front();
            }

            if (flipped == nums[i]) {
                if (i + k > n) {
                    return -1;
                }
                flipQueue.push_back(1);
                flipped ^= 1;
                result += 1;
            } else {
                flipQueue.push_back(0);
            }
        }
        return result;
    }
};
