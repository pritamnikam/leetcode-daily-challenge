/*
227. Basic Calculator II
https://leetcode.com/problems/basic-calculator-ii/

Given a string s which represents an expression, evaluate this expression and return its value.

The integer division should truncate toward zero.

You may assume that the given expression is always valid. All intermediate results will be in the range of [-231, 231 - 1].

Note: You are not allowed to use any built-in function which evaluates strings as mathematical expressions, such as eval().



Example 1:

Input: s = "3+2*2"
Output: 7
Example 2:

Input: s = " 3/2 "
Output: 1
Example 3:

Input: s = " 3+5 / 2 "
Output: 5


Constraints:

1 <= s.length <= 3 * 105
s consists of integers and operators ('+', '-', '*', '/') separated by some number of spaces.
s represents a valid expression.
All the integers in the expression are non-negative integers in the range [0, 231 - 1].
The answer is guaranteed to fit in a 32-bit integer.

*/

using namespace std;

#include <vector>
#include <algorithm>
#include <string>
#include <iostream>

namespace {
    class Solution {
    public:
        int calculate(string s) {
            int length = s.length();
            if (length == 0)
                return 0;

            int currentNumber = 0,
                lastNumber = 0,
                result = 0;

            char sign = '+';
            for (int i = 0; i < length; i++) {
                char currentChar = s[i];
                if (isdigit(currentChar)) {
                    currentNumber = (currentNumber * 10) + (currentChar - '0');
                }

                if (!isdigit(currentChar) &&
                    !iswspace(currentChar) ||
                    i == length - 1) {

                    if (sign == '+' || sign == '-') {
                        result += lastNumber;
                        lastNumber = (sign == '+') ? currentNumber : -currentNumber;
                    }
                    else if (sign == '*') {
                        lastNumber = lastNumber * currentNumber;
                    }
                    else if (sign == '/') {
                        lastNumber = lastNumber / currentNumber;
                    }
                    sign = currentChar;
                    currentNumber = 0;
                }
            }

            result += lastNumber;
            return result;
        }
    };
}// namespace

void testBasicCalculatorII() {
// Input: s = "3+2*2"
// Output : 7
    string s = "3+2*2";
    cout << "Basic Calculator II: " << Solution().calculate(s) << endl;
}
