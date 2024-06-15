// 75. Sort Colors
// https://leetcode.com/problems/sort-colors

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int colors[3] = {0, 0, 0};
        for (int n: nums) {
            colors[n]++;
        }

        int count = 0;
        for (int i = 0; i < 3; i++) {
            while(colors[i] != 0) {
                colors[i]--;
                nums[count] = i;
                count++;
            }
        }
    }
};
