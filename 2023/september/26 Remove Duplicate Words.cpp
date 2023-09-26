// 316. Remove Duplicate Words
// https://leetcode.com/problems/remove-duplicate-letters

using namespace std;

#include <iostream>
#include <string>
#include <stack>
#include <unordered_set>
#include <unordered_map>

namespace {
class Solution {
public:
    string removeDuplicateLetters(string s) {
        stack<char> stack;
        unordered_set<char> seen;
        unordered_map<char, int> lastOccuranceMap;

        //Keep the last occurrence of every char
        for (int i = 0; i < s.length(); i++) {
            lastOccuranceMap[s[i]] = i;
        }


        //For every char add to a stack
        for (int i = 0; i < s.length(); ++i) {
            char ch = s[i];

            // if |ch| not seen so far
            if (seen.count(ch) == 0) {
                // keep removing if:
                // 1. The top of the stack is greater than |ch|
                // 2. and it's not lastOccuranceMap for char at the top of the stack
                while (!stack.empty() 
                        && ch < stack.top() 
                        && lastOccuranceMap[stack.top()] > i) {
                    seen.erase(stack.top());
                    stack.pop();
                }

                // add to seen set
                seen.insert(ch);

                // push to stack
                stack.push(ch);
            }
        }

        string output;
        while (!stack.empty()) {
            output += stack.top();
            stack.pop();
        }

        reverse(output.begin(), output.end());
        return output;
    }
};
}
