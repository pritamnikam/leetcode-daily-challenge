/*
Factorial Trailing Zeroes

Given an integer n, return the number of trailing zeroes in n!.

Note that n! = n * (n - 1) * (n - 2) * ... * 3 * 2 * 1.



Example 1:

Input: n = 3
Output: 0
Explanation: 3! = 6, no trailing zero.
Example 2:

Input: n = 5
Output: 1
Explanation: 5! = 120, one trailing zero.
Example 3:

Input: n = 0
Output: 0


Constraints:

0 <= n <= 104


Follow up: Could you write a solution that works in logarithmic time complexity?


Optimal Approach
Observe that number of trailing zeroes in a number will be the highest power of 10 present in the number.

Now we know that 10n = 2n * 5n. So, the highest power of 10 will be equal to the minimum of the highest power of 2 and the highest power of 5 present in n!. 
We can observe that the highest power of 2 is always going to be less than or equal to the highest power of 5 in any value of n!. 

So, our problem boils down to finding the highest power of 5 in n!.

*/

class Solution {
private:
    int getTrailingZeroes1(int n) {
        int zeroes = 0;
        int power = 5;
        for (int i = 1;; i++) {
            zeroes += (n / power);
            if (n / power == 0) {
                break;
            }
            power *= 5;
        }
        return zeroes;
    }

    int getTrailingZeroes2(int n) {
        int factorial = 1;
        for (int i = 1; i <= n; i++) {
            factorial *= i;
        }
        int zeroes = 0;
        while (factorial % 10 == 0) {
            zeroes++;
            factorial /= 10;
        }
        return zeroes;
    }

public:
    int trailingZeroes(int n) {

    }
};