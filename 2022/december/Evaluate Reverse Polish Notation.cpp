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

#include <iostream>
#include <vector>
#include <stack>
#include <string>

namespace {
	class Solution {
	public:
		int evalRPN(vector<string>& tokens) {
            stack<int> stack;
            for (string& token : tokens) {
                if (isOperator(token)) {
                    int x = stack.top(); stack.pop();
                    int y = stack.top(); stack.pop();

                    stack.push(evaluate(token, x, y));
                }
                else {
                    stack.push(stoi(token));
                }
            }

            return stack.top();
		}

	private:
        bool isOperator(const string& str) {
            if (str.length() > 1) 
                return false;

            char operation = str[0];
            return  operation == '+' 
                || operation == '-' 
                || operation == '/' 
                || operation == '*';
        }

        int evaluate(const string& str, int op1, int op2) {
            char operation = str[0];
            if (operation == '+') return op1 + op2;
            else if (operation == '-') return op1 - op2;
            else if (operation == '/') return op1 / op2;
            return op1 * op2;
        }
	};
}  // namespace

void testEvaluateReversePolishNotation() {
    // Input: tokens = ["2","1","+","3","*"], Output: 9, 
    // Explanation : ((2 + 1) * 3) = 9
    vector<string> tokens = { "2", "1", "+", "3", "*" };
    cout << "Evaluate Reverse Polish Notation: " << Solution().evalRPN(tokens) << endl;
}
