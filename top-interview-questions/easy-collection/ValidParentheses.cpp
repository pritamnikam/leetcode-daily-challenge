/*
Valid Parentheses

Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.


Example 1:

Input: s = "()"
Output: true
Example 2:

Input: s = "()[]{}"
Output: true
Example 3:

Input: s = "(]"
Output: false


Constraints:

1 <= s.length <= 104
s consists of parentheses only '()[]{}'.

*/
using namespace std;

#include <iostream>
#include <stack>

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        // for all the char in string
        for (int i = 0; i < s.size(); ++i) {
            // push the opening braces:
            if (isOpeningBracket(s[i])) {
                st.push(s[i]);
            }
            else {
                // stack is empty:
                if (st.empty())
                    return false;

                // is matching braces:
                if (!isCorrectOrder(st.top(), s[i]))
                    return false;

                // remove matching brace
                st.pop();
            }
        }

        return st.empty();
    }

    bool isOpeningBracket(char ch) {
        return ch == '(' || ch == '{' || ch == '[';
    }

    bool isCorrectOrder(char ch1, char ch2) {
        return (ch1 == '(' && ch2 == ')') ||
                (ch1 == '{' && ch2 == '}') ||
                (ch1 == '[' && ch2 == ']');
    }
};