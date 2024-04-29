// 2997. Minimum Number of Operations to Make Array XOR equal to k
// https://leetcode.com/problems/minimum-number-of-operations-to-make-array-xor-equal-to-k

class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int finalXor = 0, count = 0;

        // 1. xor of all numbers in an array
        for (int n: nums) finalXor ^= n;
    
        // 2. Keep iterating until any of k or finalXor become zero
        while (k || finalXor) {
            // k % 2 returns the rightmost bit in k
            // finalXor % 2 returns the rightmost bit in finalXor
            if (
                k % 2 != finalXor % 2
            ) {
                // increment counter it bits doesn't match
                count++;
            }


            // Remove the last bit from both integers
            k /= 2;
            finalXor /= 2;
        }

        return count;
    }
};
