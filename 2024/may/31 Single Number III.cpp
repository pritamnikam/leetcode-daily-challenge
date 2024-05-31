// 260. Single Number III
// https://leetcode.com/problems/single-number-iii

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int XOR = accumulate(
            nums.begin(), 
            nums.end(), 
            0, 
            bit_xor<>()
        );

        int i = 0;
        while (((XOR >> i) & 1) == 0) {
            i++;
        }

        int x = 0, y = 0;
        for (int n: nums) {
            if (((n >> i) & 1) == 0) {
                x ^= n;
            } else {
                y ^= n;
            }
        }
        return {x, y};
    }
};
