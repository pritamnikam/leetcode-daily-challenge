// 1760. minimum-limit-of-balls-in-a-bag
// https://leetcode.com/problems/minimum-limit-of-balls-in-a-bag

class Solution {
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        // binary search bounds
        int l = 1, r = 0;

        for (int n: nums) {
            r = max(r, n);
        }

        //Perform binary search to find the optimal maxBallsInBag

        while (l < r) {
            int m = l + (r - l)/2;

            if (isPossible(m, nums, maxOperations)) {
                // if possible try a smaller value (shift r to m)
                r = m;
            } else {
                // if not possible, try a larger value (shift l to m + 1)
                l = m + 1;
            }
        }

        // return the smallest possible value of maxBallsInBag
        return l;
    }


private:
    // Helper function to check if a distribution is possible for a given maxBallsInBag
    bool isPossible(int maxBallsInBag, vector<int>& nums, int maxOperations) {
        int totalOperations = 0;

        // Iterate through each bag in the array
        for (int num: nums) {
            // Calculate the number of operations needed to split this bag
            int operations = ceil(num / (double)maxBallsInBag) - 1;
            totalOperations += operations;

            // Total operations exceed maxOperations, return false
            if (totalOperations > maxOperations) {
                return false;
            }
        }

        // We can split the balls within the allowed operations, and return true
        return true;
    }
};
