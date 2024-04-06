// 1249. Minimum Remove to Make Valid Parentheses
// https://leetcode.com/problems/minimum-remove-to-make-valid-parentheses/

class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<pair<char, int>> stack;
        addParanethesisToStack(s, stack);

        unordered_set<int> set;
        getIndexSet(stack, set);

        string out;
        for (int i = 0; i < s.length(); ++i) {
            if (set.count(i)) continue;

            out += s[i];
        }

        return out;
    }

private:
    void getIndexSet(
        stack<pair<char, int>>& stack,
        unordered_set<int>& set
    ) {
        while (!stack.empty()) {
            auto& it = stack.top();
            set.insert(it.second);
            stack.pop();
        }
    }


    void addParanethesisToStack(
        string& s,
        stack<pair<char, int>>& stack
    ) {
        for (int i = 0; i < s.length(); ++i) {
            char ch = s[i];
            if (ch == ')') {
                if (
                    stack.empty() ||
                    stack.top().first != '('
                ) {
                    stack.push({ch, i});
                } else {
                    stack.pop();
                }
            } else if (ch == '(') {
                stack.push({ch, i});
            }
        }
    }
};
