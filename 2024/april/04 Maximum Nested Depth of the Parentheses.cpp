// 1614. Maximum Nested Depth of the Parentheses
// https://leetcode.com/problems/maximum-nesting-depth-of-the-parentheses/

class Solution {
public:
    int maxDepth(string s) {
        int answer = 0;
        int openBrackets = 0;

        for (char ch: s) {
            if (ch == '(') {
                ++openBrackets;
            } else if (ch == ')') {
                --openBrackets;
            }

            answer = max(answer, openBrackets);
        }

        return answer;
    }
};
