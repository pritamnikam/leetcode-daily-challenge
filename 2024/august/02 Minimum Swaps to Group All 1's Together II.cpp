// 2134. Minimum Swaps to Group All 1's Together II
// https://leetcode.com/problems/minimum-swaps-to-group-all-1s-together-ii/


class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int op1 = helper(nums, 0); // group all 0
        int op2 = helper(nums, 1); // group all 1
        return min(op1, op2);
    }

    private:
    int helper(vector<int>& data, int val) {
        int length = data.size();
        int totalValCount = 0;
        for (int i = length - 1; i>= 0; i--) {
            if (data[i] == val) {
                totalValCount++;
            }
        }
        if (totalValCount == 0 || totalValCount == length) {
            return 0;
        }

        // sliding window
        return slidingWindow(
            data, val, totalValCount
        );
    }

    int slidingWindow(vector<int>& data, int val, int totalValCount) {
        int start = 0, end = 0;
        int maxValInWindow = 0, currentValInWindow = 0;
        int length = data.size();

        // Initial window setup: count the number of `val` in the first window
        // of size `totalValCount`
        while (end < totalValCount) {
            if (data[end++] == val) currentValInWindow++;
        }
        maxValInWindow = max(maxValInWindow, currentValInWindow);

        // Slide the window across the array to find the maximum number of
        // `val` in any window
        while (end < length) {
            if (data[start++] == val) currentValInWindow--;
            if (data[end++] == val) currentValInWindow++;
            maxValInWindow = max(maxValInWindow, currentValInWindow);
        }

        // Minimum swaps are the total `val` minus the maximum found in any
        // window
        return totalValCount - maxValInWindow;
    }
};
