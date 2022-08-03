/*
Happy Number

Write an algorithm to determine if a number n is happy.

A happy number is a number defined by the following process:

Starting with any positive integer, replace the number by the sum of the squares of its digits.
Repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1.
Those numbers for which this process ends in 1 are happy.
Return true if n is a happy number, and false if not.



Example 1:

Input: n = 19
Output: true
Explanation:
12 + 92 = 82
82 + 22 = 68
62 + 82 = 100
12 + 02 + 02 = 1
Example 2:

Input: n = 2
Output: false


Constraints:

1 <= n <= 231 - 1

*/

class Solution {
    // O(log n) time complexity
    int getNextNumber(int n) {
        int totalSum = 0;
        while (n) {
            int d = n % 10;
            n = n / 10;
            totalSum += (d * d);
        }

        return totalSum;
    }

public:
#if 0
    // 1. Detect Cycles with a HashSet
    bool isHappy(int n) {
        unordered_set<int> seen;
        while (n != 1 && seen.find(n) == seen.end()) {
            seen.insert(n);
            n = getNextNumber(n);
        }

        return n == 1;
    }
#endif

#if 0
    // 2. Floyd's Cycle-Finding Algorithm - 2 pinters
    bool isHappy(int n) {
        int slow = n;
        int fast = getNextNumber(n);
        while (slow != fast && fast != 1) {
            slow = getNextNumber(slow);
            fast = getNextNumber(getNextNumber(fast));
        }

        return fast == 1;
    }
#endif

#if 0
    // 3. Hardcoding the Only Cycle (Advanced)
    // {4 -> 16 -> 37 -> 58 -> 89 -> 145 -> 42 -> 20 -> 4}
    bool isHappy(int n) {
        unordered_set<int> hardCodedCycleSet = { 4, 16, 37, 58, 89, 145, 42, 20 };
        while (n != 1 && hardCodedCycleSet.find(n) == hardCodedCycleSet.end()) {
            n = getNextNumber(n);
        }
        return n == 1;
    }
#endif

    // 4. An Alternative Implementation
    bool isHappy(int n) {
        while (n != 1 && n != 4)
            n = getNextNumber(n);
        return n == 1;
    }
};