// 719. Find Kth Smallest Pair Distance
// https://leetcode.com/problems/find-k-th-smallest-pair-distance

class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(
            nums.begin(),
            nums.end()
        );
        int n = nums.size();

        // init binary search rage
        int lo = 0, 
            hi = nums[n - 1] - nums[0];
        
        while (lo < hi) {
            int mid = lo + (hi - lo)/2;
            int count = countPairsWithMaxDistance(nums, mid);

            if (count < k) {
                lo = mid + 1;
            } else {
                hi = mid;
            }
        }
        return lo;
    }

private:
    // Count number of pairs with distance <= maxDistance using a moving window
    int countPairsWithMaxDistance(vector<int>& nums, int maxDistance) {
        int count = 0;
        int arraySize = nums.size();
        int left = 0;

        for (int right = 0; right < arraySize; ++right) {
            // Adjust the left pointer to maintain the window with distances <=
            // maxDistance
            while (nums[right] - nums[left] > maxDistance) {
                ++left;
            }
            // Add the number of valid pairs ending at the current right index
            count += right - left;
        }
        return count;
    } 
};
