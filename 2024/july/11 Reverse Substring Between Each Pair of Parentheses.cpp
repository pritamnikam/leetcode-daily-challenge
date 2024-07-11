// 1190. Reverse Substring Between Each Pair of Parentheses
// https://leetcode.com/problems/reverse-substrings-between-each-pair-of-parentheses/

class Solution {
public:
    string reverseParentheses(string s) {
        stack<int> openParenthesesIndices;
        string result;

        for (char ch: s) {
            if (ch == '(') {
                openParenthesesIndices.push(result.length());
            } else if (ch == ')') {
                int start = openParenthesesIndices.top();
                openParenthesesIndices.pop();
                reverse(result.begin() + start, result.end());
            } else {
                result += ch;
            }
        }
        return result;
    }
};
