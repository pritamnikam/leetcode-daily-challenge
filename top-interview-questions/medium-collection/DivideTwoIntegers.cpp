/*
Divide Two Integers

Given two integers dividend and divisor, divide two integers without using multiplication, division, and mod operator.

The integer division should truncate toward zero, which means losing its fractional part. For example, 8.345 would be truncated to 8, and -2.7335 would be truncated to -2.

Return the quotient after dividing dividend by divisor.

Note: Assume we are dealing with an environment that could only store integers within the 32-bit signed integer range: [−231, 231 − 1]. For this problem, if the quotient is strictly greater than 231 - 1, then return 231 - 1, and if the quotient is strictly less than -231, then return -231.


Example 1:
Input: dividend = 10, divisor = 3
Output: 3
Explanation: 10/3 = 3.33333.. which is truncated to 3.

Example 2:
Input: dividend = 7, divisor = -3
Output: -2
Explanation: 7/-3 = -2.33333.. which is truncated to -2.


Constraints:

-231 <= dividend, divisor <= 231 - 1
divisor != 0




public class DivideTwoIntegers {

    public int divide(int dividend, int divisor) {
        // Check for overflow
        if (divisor == 0 || (dividend == Integer.MIN_VALUE && divisor == -1)) {
            return Integer.MAX_VALUE;
        }
        
        // Sign of result
        int sign = (dividend > 0 && divisor < 0) || (dividend < 0 && divisor > 0) ? -1 : 1;
        
        // Quotient
        int quotient = 0;
        
        // Take the absolute value
        long absoluteDividend = Math.abs((long) dividend);
        long absoluteDivisor = Math.abs((long) divisor);
        
        // Loop until the  dividend is greater than divisor
        while (absoluteDividend >= absoluteDivisor) {
            // This represents the number of bits shifted or
            // how many times we can double the number
            int shift = 0;
            while (absoluteDividend >= (absoluteDivisor << shift)) {
                shift++;
            }
            
            // Add the number of times we shifted to the quotient
            quotient += (1 << (shift - 1));
            
            // Update the dividend for the next iteration
            absoluteDividend -= absoluteDivisor << (shift - 1);
        }
        
        return sign == -1 ? -quotient : quotient;
    }
}

*/
using namespace std;
#include <iostream>

class Solution {
public:
    int divide(int dividend, int divisor) {
        // boundry cases:
        if (dividend == 0) return 0;
        if (divisor == 1) return dividend;
        if (divisor == -1) return dividend == INT_MIN ? INT_MAX : 0 - dividend;

        bool neg = (dividend < 0) ^ (divisor < 0);
        int count = 0;
        long long a = abs(dividend);
        long long b = abs(divisor);
        int ct = 1;

        while (b <= a) {
            count += ct;
            a = a - b;
            b = b << 1;
            ct = ct << 1;
        }

        divisor = abs(divisor);

        while (divisor <= a) {
            count++;
            a -= divisor;
        }

        return neg ? 0 - count : count;


    }

    // Function to divide a by b and
    // return floor value it
    int divide(long long dividend, long long divisor) {

        // Calculate sign of divisor i.e.,
        // sign will be negative only iff
        // either one of them is negative
        // otherwise it will be positive
        int sign = ((dividend < 0) ^ (divisor < 0)) ? -1 : 1;

        // remove sign of operands
        dividend = abs(dividend);
        divisor = abs(divisor);

        // Initialize the quotient
        long long quotient = 0, temp = 0;

        // test down from the highest bit and
        // accumulate the tentative value for
        // valid bit
        for (int i = 31; i >= 0; --i) {

            if (temp + (divisor << i) <= dividend) {
                temp += divisor << i;
                quotient |= 1LL << i;
            }
        }
        //if the sign value computed earlier is -1 then negate the value of quotient
        if (sign == -1) quotient = -quotient;

        return quotient;
    }


/*
Let a/b = c.
Take log on both sides
log(a) – log(b) = log(c)
Now Log of RHS can be written as exp in LHS
Final formula is : exp(log(a) – log(b)) = c
*/

// Returns the quotient of dividend/divisor.
    void Divide(int a, int b)
    {
        long long dividend = (long long)a;
        long long divisor = (long long)b;

        // Calculate sign of divisor i.e.,
        // sign will be negative only if
        // either one of them is negative
        // otherwise it will be positive

        long long sign = (dividend < 0) ^ (divisor < 0) ? -1 : 1;

        // Remove signs of dividend and divisor
        dividend = abs(dividend);
        divisor = abs(divisor);

        // Zero division Exception.
        if (divisor == 0) {
            cout << "Cannot Divide by 0" << endl;
            return;
        }

        if (dividend == 0) {
            cout << a << " / " << b << " is equal to : "
                << 0 << endl;
            return;
        }

        if (divisor == 1) {
            cout << a << " / " << b << " is equal to : "
                << sign * dividend << endl;
            return;
        }

        // Using Formula derived above.
        cout << a << " / " << b << " is equal to : "
            << sign * exp(log(dividend) - log(divisor))
            << endl;
    }
};