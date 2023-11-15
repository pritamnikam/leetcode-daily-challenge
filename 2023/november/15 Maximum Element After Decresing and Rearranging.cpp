// 1846. Maximum Element After Decresing and Rearranging
// https://leetcode.com/problems/maximum-element-after-decreasing-and-rearranging

class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        // 1. Sort the elements in non-decresing order
        sort(arr.begin(), arr.end());;

        int ans = 1;
        for (int i = 1; i < arr.size(); i++) {
            if (arr[i] >= ans + 1) {
                ans++;
            }
        }

        return ans;
    }
};
