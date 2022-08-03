/*
Sum of Two Integers

Given two integers a and b, return the sum of the two integers without using the operators + and -.


Example 1:
Input: a = 1, b = 2
Output: 3

Example 2:
Input: a = 2, b = 3
Output: 5

Constraints:
-1000 <= a, b <= 1000


If x and y don’t have set bits at same position(s), then bitwise XOR (^) of x and y gives the sum of x and y. 
To incorporate common set bits also, bitwise AND (&) is used. Bitwise AND of x and y gives all carry bits. 
We calculate (x & y) << 1 and add it to x ^ y to get the required result.

*/

class Solution {
public:
    int getSum(int a, int b) {
        // Iterate till there is no carry
        while (b) {
            // carry now contains common
            //set bits of x and y
            unsigned carry = a & b;

            // Sum of bits of x and y where at
            // least one of the bits is not set
            a = a ^ b;

            // Carry is shifted by one so that adding
            // it to x gives the required sum
            b = carry << 1;
        }

        return a;
    }
};