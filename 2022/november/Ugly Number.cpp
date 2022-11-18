/*
263. Ugly Number
https://leetcode.com/problems/ugly-number/

An ugly number is a positive integer whose prime factors are limited to 2, 3, and 5.

Given an integer n, return true if n is an ugly number.



Example 1:

Input: n = 6
Output: true
Explanation: 6 = 2 × 3

Example 2:
Input: n = 1
Output: true
Explanation: 1 has no prime factors, therefore all of its prime factors are limited to 2, 3, and 5.

Example 3:
Input: n = 14
Output: false
Explanation: 14 is not ugly since it includes the prime factor 7.


Constraints:

-231 <= n <= 231 - 1

*/

using namespace std;

#include <vector>
#include <math.h>
#include <iostream>

namespace {
    class Solution {
        vector<int> getPrimeFactors(int n) {
            vector<int> result;
            while (n % 2 == 0) {
                result.emplace_back(2);
                n = n / 2;
            }

            for (int i = 3; i <= sqrt(n); i += 2) {
                while (n % i == 0) {
                    result.emplace_back(i);
                    n = n / i;
                }
            }

            if (n > 2)
                result.emplace_back(n);

            return result;
        }

    public:
        bool isUgly(int n) {
            if (n < 1) return false;
            if (n == 1) return true;
            vector<int> factors = getPrimeFactors(n);

            for (int factor : factors) {
                if (factor != 2 && factor != 3 && factor != 5)
                    return false;
            }

            return true;
        }
    };
    
    class Solution2 {
    public:
        bool isUgly(int n) {
            // A non-positive integer cannot be ugly
            if (n <= 0) {
                return false;
            }

            // Factorize by dividing with permitted factors.
            for (auto factor : { 2, 3, 5 }) {
                n = keepDividingWhenDivisible(n, factor);
            }

            // Check if the integer is reduced to 1 or not.
            return n == 1;
        }

        // Keep dividing dividend by divisor when division is possible.
        int keepDividingWhenDivisible(int dividend, int divisor) {
            while (dividend % divisor == 0) {
                dividend /= divisor;;
            }
            return dividend;
        }
    };
} // namespace

void testUglyNumber() {
    cout << "Ugly Number (6): " << Solution().isUgly(6) << endl;
    cout << "Ugly Number (14): " << Solution().isUgly(14) << endl;
}
