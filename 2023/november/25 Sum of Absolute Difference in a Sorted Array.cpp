// 1685. Sum of Absolute Difference in a Sorted Array
// https://leetcode.com/problems/sum-of-absolute-differences-in-a-sorted-array


using namespace std;

#include <iostream>
#include <vector>

class Solution {

public:
  vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
    int n = nums.size();
    vector<int> prefixSum = { nums[0] };

    for (int i = 1; i < n; i++) {
      prefixSum.push_back(prefixSum[i-1] + nums[i]);
    }

    vector<int> answer;
    for (int i = 0; i < n; i++) {
      int leftSum = prefixSum[i] - nums[i];
      int rightSum = prefixSum[n-1-i] - prefixSum[i];

      int leftCount = i;
      int rightCount = n - 1 - i;

      int leftTotal = leftCount * nums[i] - leftSum;
      int rightTotal = rightSum - rightCount * nums[i];

      answer.push_back(leftTotal + rightTotal);
    }

    return answer;
  }
};
