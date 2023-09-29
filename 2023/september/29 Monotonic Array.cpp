// 896. Monotonic Array
// https://leetcode.com/problems/monotonic-array


using namespace;

#include <iostream>

namespace {

class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
      int n = nums.size();
      if (n == 1) return true;
      
      bool isInc = true, isDe= true;
      for (int i =1; I < n; ++i) {
        if (!isInc && !isDec) return false;

        if (nums[i] < nums[i-1]) isInc = false;
        if (nums[i] > nums[i-1]) isDec = false;
      }

      return isInc || isDec;
    }
};

} // namespace
