/*
150. Evaluate Reverse Polish Notation
https://leetcode.com/problems/evaluate-reverse-polish-notation/

Evaluate the value of an arithmetic expression in Reverse Polish Notation.

Valid operators are +, -, *, and /. Each operand may be an integer or another expression.

Note that division between two integers should truncate toward zero.

It is guaranteed that the given RPN expression is always valid. That means the expression would always evaluate to a result, and there will not be any division by zero operation.



Example 1:

Input: tokens = ["2","1","+","3","*"]
Output: 9
Explanation: ((2 + 1) * 3) = 9
Example 2:

Input: tokens = ["4","13","5","/","+"]
Output: 6
Explanation: (4 + (13 / 5)) = 6
Example 3:

Input: tokens = ["10","6","9","3","+","-11","*","/","*","17","+","5","+"]
Output: 22
Explanation: ((10 * (6 / ((9 + 3) * -11))) + 17) + 5
= ((10 * (6 / (12 * -11))) + 17) + 5
= ((10 * (6 / -132)) + 17) + 5
= ((10 * 0) + 17) + 5
= (0 + 17) + 5
= 17 + 5
= 22


Constraints:

1 <= tokens.length <= 104
tokens[i] is either an operator: "+", "-", "*", or "/", or an integer in the range [-200, 200].

*/

using namespace std;

#include <vector>
#include <string>
#include <iostream>
#include <stack>

namespace {
    class Solution {
        bool isOperator(const string& str) {
            if (str.length() > 1) return false;
            char operation = str[0];
            return  operation == '+' ||
                operation == '-' ||
                operation == '/' ||
                operation == '*';
        }

        int toInt(const string& str) {
            return stoi(str);
        }

        int evaluate(const string& str, int op1, int op2) {
            char operation = str[0];
            if (operation == '+')
                return op1 + op2;
            else if (operation == '-')
                return op1 - op2;
            else if (operation == '/')
                return op1 / op2;

            return op1 * op2;
        }

    public:
        int evalRPN(vector<string>& tokens) {
            stack<int> stack;
            for (const string& token : tokens) {
                if (isOperator(token)) {
                    int op2 = stack.top(); stack.pop();
                    int op1 = stack.top(); stack.pop();

                    stack.push(evaluate(token, op1, op2));
                }
                else {
                    stack.push(toInt(token));
                }
            }

            return stack.top();
        }
    };
}

void testEvalRPN() {
    vector<string> tokens = { "10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+" };
    cout << "Evaluate Reverse Polish Notation: " << Solution().evalRPN(tokens) << endl;
}