/*
Power of Three

Given an integer n, return true if it is a power of three. Otherwise, return false.
An integer n is a power of three, if there exists an integer x such that n == 3x.

Example 1:
Input: n = 27
Output: true

Example 2:
Input: n = 0
Output: false

Example 3:
Input: n = 9
Output: true


Constraints:
-231 <= n <= 231 - 1

Follow up: Could you solve it without loops/recursion?

*/

/*
Solution
In this article we will look into ways of speeding up simple computations and why that is useful in practice.


Approach 1: Loop Iteration
One simple way of finding out if a number n is a power of a number b is to keep dividing n by b as long as the remainder is 0. This is because we can write

\begin{aligned} n &= b^x \\ n &= b \times b \times \ldots \times b \end{aligned}
n
n
​

=b
x

=b×b×…×b
​


Hence it should be possible to divide n by b x times, every time with a remainder of 0 and the end result to be 1.


Notice that we need a guard to check that n != 0, otherwise the while loop will never finish. For negative numbers, the algorithm does not make sense, so we will include this guard as well.

Complexity Analysis

Time complexity : O(\log_b(n))O(log
b
​
 (n)). In our case that is O(\log_3n)O(log
3
​
 n). The number of divisions is given by that logarithm.

Space complexity : O(1)O(1). We are not using any additional memory.

*/

class Solution {
public:
    bool isPowerOfThree(int n) {
        if (n < 1) {
            return false;

            while (n % 3 == 0) {
                n /= 3;
            }

            return n == 1;
        }
    }
};

/*
Approach 2: Base Conversion
In Base 10, all powers of 10 start with the digit 1 and then are followed only by 0 (e.g. 10, 100, 1000). This is true for other bases and their respective powers. For instance in base 2, the representations of 10_210
2
​
 , 100_2100
2
​
  and 1000_21000
2
​
  are 2_{10}2
10
​
 , 4_{10}4
10
​
  and 8_{10}8
10
​
  respectively. Therefore if we convert our number to base 3 and the representation is of the form 100...0, then the number is a power of 3.

Proof

Given the base 3 representation of a number as the array s, with the least significant digit on index 0, the formula for converting from base 3 to base 10 is:

\sum_{i=0}^{len(s) - 1} s[i] * 3^{i}∑
i=0
len(s)−1
​
 s[i]∗3
i


Therefore, having just one digit of 1 and everything else 0 means the number is a power of 3.

Implementation

All we need to do is convert [1] the number to base 3 and check if it is written as a leading 1 followed by all 0.

A couple of built-in Java functions will help us along the way.


The code above converts number into base base and returns the result as a String. For example, Integer.toString(5, 2) == "101" and Integer.toString(5, 3) == "12".


*/

class Solution {
public:
    bool isPowerOfThree(int n) {
        if (n < 1) {
            return false;
        }

        while (n % 3 == 0) {
           n = n / 3;
        }

        return n == 1;
    }
};