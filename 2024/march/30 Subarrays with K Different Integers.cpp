// 992. Subarrays with K Different Integers
// https://leetcode.com/problems/subarrays-with-k-different-integers

class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {

        int totalCount = 0, left = 0, right = 0, currentCount = 0, n = nums.size();
        // store distinct occurrences of values
        vector<int> distinctCount(n + 1, 0);


        while (right < n) {
            // Increment the count of the current element in the window
            if (++distinctCount[nums[right++]] == 1) {
                // new distinct element, decrement k
                --k;
            }

            // If more than k distinct elements in a window
            if (k < 0) {
                // shrink window by left
                --distinctCount[nums[left++]];
                k++;
                currentCount = 0;
            }

            //If found the exact k distinct elements
            if (k == 0) {
                //Keep on shrinking from the left until reaches the distinct element count of 1
                while (distinctCount[nums[left]] > 1) {
                    --distinctCount[nums[left++]];
                    currentCount++;
                }
                //Add the count of subarrays with k distinct elements to the total count
                totalCount += (currentCount + 1);
            }
        }

        return totalCount;
    }
};
