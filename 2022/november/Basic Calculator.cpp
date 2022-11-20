/*
224. Basic Calculator
https://leetcode.com/problems/basic-calculator/

Given a string s representing a valid expression, implement a basic calculator to evaluate it, 
and return the result of the evaluation.

Note: You are not allowed to use any built-in function which evaluates strings as mathematical 
expressions, such as eval().

Example 1:
Input: s = "1 + 1"
Output: 2

Example 2:
Input: s = " 2-1 + 2 "
Output: 3

Example 3:
Input: s = "(1+(4+5+2)-3)+(6+8)"
Output: 23


Constraints:
1 <= s.length <= 3 * 105
s consists of digits, '+', '-', '(', ')', and ' '.
s represents a valid expression.
'+' is not used as a unary operation (i.e., "+1" and "+(2 + 3)" is invalid).
'-' could be used as a unary operation (i.e., "-1" and "-(2 + 3)" is valid).
There will be no two consecutive operators in the input.
Every number and running calculation will fit in a signed 32-bit integer.

*/

#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <iostream>

using namespace std;

/*
Input: s = "(1+(4+5+2)-3)+(6+8)"
Output: 23

iterate char by char
use stack
sign

when we encounter open bracket '(' push it to stack
when we enounter clossing bracket ')' pop from the stack
*/

namespace {
    class Solution {
    public:
        int calculate(string s) {
            stack<int> stack;
            int sum = 0;
            int sign = 1;

            for (int i = 0; i < s.length(); ++i) {
                // we have 5 cases:
                // 1. number
                if (s[i] >= '0' and s[i] <= '9') {
                    int num = 0;
                    while (i < s.length() and s[i] >= '0' and s[i] <= '9') {
                        num = num * 10 + (s[i] - '0');
                        ++i;
                    }

                    sum += num * sign;
                    --i;
                }

                // 2. +
                else if (s[i] == '+') {
                    sign = 1;
                }

                // 3. -
                else if (s[i] == '-') {
                    sign = -1;
                }

                // 4. (
                else if (s[i] == '(') {
                    stack.push(sum);
                    stack.push(sign);

                    sum = 0;
                    sign = 1;
                }

                // 5. )
                else if (s[i] == ')') {
                    sum = sum * stack.top();
                    stack.pop();

                    sum += stack.top();
                    stack.pop();
                }
            }

            return sum;
        }
    };
}  // namespace

void testBasicCalculator() {
    cout << "Basic Calculator: " << Solution().calculate("(1+(4+5+2)-3)+(6+8)") << endl;
}
