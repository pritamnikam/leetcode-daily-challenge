// 2779. maximum-beauty-of-an-array-after-applying-operation
// https://leetcode.com/problems/maximum-beauty-of-an-array-after-applying-operation/

class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int right = 0;
        int maxBeauty = 0;

        // iterate from left to end
        for (int left = 0; left < nums.size(); left++) {
            // expand the window size
            while (
                right < nums.size() &&
                (nums[right] - nums[left] <= 2 * k)
            ) {
                right++;
            }

            // update the maximum beaty
            maxBeauty = max(maxBeauty, right - left);
        }
        return maxBeauty;
    }
};
