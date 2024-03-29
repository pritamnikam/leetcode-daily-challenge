// 1793. Maximum Array of Good Subarray
// https://leetcode.com/problems/maximum-score-of-a-good-subarray/
using namespace std;

#include <iostream>
#include <vector>

namespace {

class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> left(n, -1);
        vector<int> stack;

        // 
        for (int i = n -1; i>= 0; i--) {
            while (!stack.empty() && nums[stack.back()] > nums[i]) {
                left[stack.back()] = i;
                stack.pop_back();
            }

            stack.push_back(i);
        }


        vector<int> right(n , n);
        stack.clear();
        for (int i = 0; i < n; i++) {
            while (!stack.empty() && nums[stack.back()] > nums[i]) {
                right[stack.back()] = i;
                stack.pop_back();
            }
        
            stack.push_back(i);
        }

        int answer = 0;
        for (int i = 0; i < n; i++) {
            if (left[i] < k && right[i] > k) {
                answer = max(answer, nums[i] * (right[i] - left[i] - 1));
            }
        }
        return answer;

    }
};

} // namespace
