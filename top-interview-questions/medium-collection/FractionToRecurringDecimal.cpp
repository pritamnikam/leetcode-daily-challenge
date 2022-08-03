/*
Fraction to Recurring Decimal

Given two integers representing the numerator and denominator of a fraction, return the fraction in string format.

If the fractional part is repeating, enclose the repeating part in parentheses.

If multiple answers are possible, return any of them.

It is guaranteed that the length of the answer string is less than 104 for all the given inputs.



Example 1:
Input: numerator = 1, denominator = 2
Output: "0.5"

Example 2:
Input: numerator = 2, denominator = 1
Output: "2"

Example 3:
Input: numerator = 4, denominator = 333
Output: "0.(012)"


Constraints:
-231 <= numerator, denominator <= 231 - 1
denominator != 0

*/

using namespace std

#include <string>
#include <vector>
#include <unordered_set>

class Solution {

    string calculateFraction(long long n, long long d) {
        string ans;
        unordered_map<long long, int> mp;
        while (n) {
            n *= 10;
            ans += to_string(n / d);
            n = n % d;
            if (mp.count(n)) {
                ans.insert(mp[n], "(");
                ans += ")";
                break;
            }

            mp[n] = ans.size();
        }

        return ans;
    }

public:
    string fractionToDecimal(int numerator, int denominator) {
        if (numerator == 0) {
            return "0";
        }

        string ans = ((numerator > 0) ^ (denominator > 0)) ? "-" : "";

        long long n = abs(numerator);
        long long d = abs(denominator);
        ans += to_string(n / d);

        n = n % d;
        if (n == 0) {
            return ans;
        }

        return ans + "." + calculateFraction(n, d);
    }
};