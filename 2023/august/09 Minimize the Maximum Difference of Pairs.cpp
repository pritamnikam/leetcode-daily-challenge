/*
2616. Minimize the Maximum Difference of Pairs
https://leetcode.com/problems/minimize-the-maximum-difference-of-pairs/


*/

using namespace std;

#include <iostream>
#include <vector>
#include <algorithm>

namespace {
class Solution {
public:
    int minimizeMax(vector<int>& nums, int p) {
        // Sort in ascending order
        sort(nums.begin(), nums.end());

        // binary search the possible set
        int n = nums.size();
        int left = 0, right = nums[n-1]-nums[0];

        while(left < right) {
            int mid = left + (right - left) / 2;

            // if there are enough pairs, look for a smaller threshold
            if (countValidPairs(nums, mid) >= p) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }

        return left;
    }

    private:
    int countValidPairs(vector<int>& nums, int threshold) {
        int index = 0, count = 0;
        while (index < nums.size() - 1) {
            // If valid pair is found, skip both numbers
            if (nums[index + 1] - nums[index] <= threshold) {
                count++;
                index++;
            }

            index++;
        }

        return count;
    }
};
} // namespace
