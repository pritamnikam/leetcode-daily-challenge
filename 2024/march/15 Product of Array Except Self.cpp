// 238. Product of Array Except Self
// https://leetcode.com/problems/product-of-array-except-self

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefixProduct(n);
        vector<int> suffixProduct(n);

        for (int i = 0; i < n; ++i) {
            prefixProduct[i] = (i == 0) ? 1 : prefixProduct[i-1] * nums[i-1];
        }

        for (int i = n -1; i >= 0; i--) {
            suffixProduct[i] = (i == n -1) ? 1 : suffixProduct[i+1]*nums[i+1];
        }

        vector<int> answer(n);
        for (int i = 0;i < n; i++) {
            answer[i] = prefixProduct[i] * suffixProduct[i];
        }
        return answer;
    }
};
