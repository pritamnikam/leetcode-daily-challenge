/*
1155. Number of Dice Rolls With Target Sum
https://leetcode.com/problems/number-of-dice-rolls-with-target-sum/

You have n dice and each die has k faces numbered from 1 to k.

Given three integers n, k, and target, return the number of possible ways (out of the kn total ways) to roll the dice so the sum of the face-up numbers equals target. Since the answer may be too large, return it modulo 109 + 7.

 

Example 1:

Input: n = 1, k = 6, target = 3
Output: 1
Explanation: You throw one die with 6 faces.
There is only one way to get a sum of 3.
Example 2:

Input: n = 2, k = 6, target = 7
Output: 6
Explanation: You throw two dice, each with 6 faces.
There are 6 ways to get a sum of 7: 1+6, 2+5, 3+4, 4+3, 5+2, 6+1.
Example 3:

Input: n = 30, k = 30, target = 500
Output: 222616187
Explanation: The answer must be returned modulo 109 + 7.
 

Constraints:

1 <= n, k <= 30
1 <= target <= 1000

*/

using namespace std;

#include <iostream>
#include <vector>

namespace {
  class Solution {
    static const int mod = pow(10, 9) + 7;
    
  public:
    
      int numRollsToTarget(int d, // no. of dice
                           int f, // faces on dice [1...f]
                           int target) {
          vector<int> ways(target + 1);
          ways[0] = 1;
          
          // for all dices
          for (int x = 1; x <= d; x++) {
              // target sum
              for (int i = target; i >= 0; i--) {
                  int way = 0;
                  for (int y = i - 1; y >= max(0, i - f);  y--) {
                    way = (way + ways[y]) % mod;
                  }
                
                  // update ways to reach target sum
                  ways[i] = way;
              }
          }
          return ways[target];
      }
  };
} // namespace
