// 1913. Maximum Product Difference Between Two Pairs
// https://leetcode.com/problems/maximum-product-difference-between-two-pairs

class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        int biggest = 0, secondBiggest = 0;
        int smallest = INT_MAX, secondSmallest = INT_MAX;

        for (int n: nums) {
            if (n > biggest) {
                secondBiggest = biggest;
                biggest = n;
            } else {
                secondBiggest = max(secondBiggest, n);
            }


            if (n < smallest) {
                secondSmallest = smallest;
                smallest = n;
            } else {
                secondSmallest = min(secondSmallest, n);
            }
        }

         return biggest * secondBiggest - smallest * secondSmallest;
    }
};

