// 844. Backspace String Compare
// https://leetcode.com/problems/backspace-string-compare/

namespace {

class Solution {
  void pushToStack(string s, stack<char>& stack) {
      for (char ch : s) {
          if (ch != '#')
              stack.push(ch);
          else if (!stack.empty())
              stack.pop();
      }
  }

public:
    bool backspaceCompare(string s, string t) {
        stack<char> s1, s2;
        pushToStack(s, s1);
        pushToStack(t, s2);

        return s1 == s2;
    }
};

} // namespace
