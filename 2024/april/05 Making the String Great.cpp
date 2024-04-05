// 1544. Making the String Great
// https://leetcode.com/problems/make-the-string-great/

class Solution {
public:
    string makeGood(string s) {
        vector<char> stack;
        for (char ch: s) {
            if (
                !stack.empty() &&
                abs(stack.back() - ch) == 32                
            ) {
                stack.pop_back();
            } else {
                stack.push_back(ch);
            }
        }

        string answer(stack.begin(), stack.end());
        return answer;
    }
};
