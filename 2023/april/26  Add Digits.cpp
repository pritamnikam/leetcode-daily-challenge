/*
258. Add Digits
https://leetcode.com/problems/add-digits/

Given an integer num, repeatedly add all its digits until the result has only one digit, and return it.

Example 1:
Input: num = 38
Output: 2
Explanation: The process is
38 --> 3 + 8 --> 11
11 --> 1 + 1 --> 2 
Since 2 has only one digit, return it.
Example 2:
Input: num = 0
Output: 0
 
Constraints:
0 <= num <= 231 - 1

Follow up: Could you do it without any loop/recursion in O(1) runtime?
*/

using namespace std;

namespace {
  /*
    Mathematical proof of digital root
        digital root
        dr10(n) = 0,         if n = 0
        dr10(n) = 9,         if n = 9k 
        dr10(n) = n mod 9,   if n != 9k
   */
  class Solution {
  public:
    int addDigits(int num) {
      if (num == 0) return 0;
      return (num % 9 == 0) ? 9 : num % 9;
    }
  };
  
} // namespace
