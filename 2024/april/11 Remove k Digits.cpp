// 402. Remove k Digits
// https://leetcode.com/problems/remove-k-digits

class Solution {
public:
    string removeKdigits(string num, int k) {
        if (k >= num.length()) {
            return "0";
        }

        stack<int> stack;
        for (char ch: num) {
            int n = ch - '0';

            while (
                k > 0 &&
                !stack.empty() &&
                stack.top() > n
            ) {
                stack.pop();
                --k;
            }

            if (
                !stack.empty() ||
                n != 0
            ) {
                stack.push(n);
            }
        }

        while (
            !stack.empty() &&
            k > 0
        ) {
            stack.pop();
            --k;
        }

        string answer;
        while (
            !stack.empty()
        ) {
            answer += to_string(stack.top());
            stack.pop();
        }

        reverse(answer.begin(), answer.end());
        return answer.empty() ? "0" : answer;
    }
};
