// 905. Sort Array By Parity
// https://leetcode.com/problems/sort-array-by-parity

using namespace std;

#include <iostream>
#include <vector>


namespace {

class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
      int readIndex = 0, writeIndex = 0;

      while (readIndex < nums.size()) {
        if (nums[readIndex] % 2 == 0) {
          swap(nums[readIndex], nums[writeIndex]);
          ++writeIndex;
        }
        ++readIndex;
      }

      return nums;
    }
};

} // namespace
