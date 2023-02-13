/*
1523. Count Odd Numbers in an Interval Range
https://leetcode.com/problems/count-odd-numbers-in-an-interval-range/

Given two non-negative integers low and high. Return the count of odd numbers between low and high (inclusive).



Example 1:

Input: low = 3, high = 7
Output: 3
Explanation: The odd numbers between 3 and 7 are [3,5,7].
Example 2:

Input: low = 8, high = 10
Output: 1
Explanation: The odd numbers between 8 and 10 are [9].


Constraints:
0 <= low <= high <= 10^9

*/

using namespace std;
#include <iostream>

namespace {
    class Solution {
    public:
        int countOdds(int low, int high) {
            int range = (high - low);
            return range / 2 + ((high % 2) || (low % 2));
        }
    };
}

void testCountOddNumbersInAnIntervalRange() {
    // Input: low = 3, high = 7 | Output: 3
    int low = 3, high = 7;
    cout << "Count Odd Numbers in an Interval Range: " << Solution().countOdds(low, high) << endl;
}
