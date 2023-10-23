// 342. Power of Four
// https://leetcode.com/problems/power-of-four/

using namespace std;

#include <iostream>
#include <vector>

namespace {

class Solution {
public:
  bool isPowerOfFour(int n) {
    int mask = 0x55555;
    return (n > 0) &&
            (n & (n - 1)) == 0 &&
            (n & mask) == n;
  }
};

}
