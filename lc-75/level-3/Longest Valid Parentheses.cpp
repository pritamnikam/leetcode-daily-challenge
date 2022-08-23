/*
32. Longest Valid Parentheses
https://leetcode.com/problems/longest-valid-parentheses/

Given a string containing just the characters '(' and ')', find the length of the 
longest valid (well-formed) parentheses substring.



Example 1:

Input: s = "(()"
Output: 2
Explanation: The longest valid parentheses substring is "()".
Example 2:

Input: s = ")()())"
Output: 4
Explanation: The longest valid parentheses substring is "()()".
Example 3:

Input: s = ""
Output: 0


Constraints:

0 <= s.length <= 3 * 104
s[i] is '(', or ')'.

*/

using namespace std;

#include <string>
#include <stack>
#include <iostream>

namespace {
	class Solution {
	public:
		// Approach 3: stack 
		// Instead of finding every possible string and checking its validity, 
		// we can make use of a stack while scanning the given string to:
		//     a. Check if the string scanned so far is valid.
		//     b. Find the length of the longest valid string.
		int longestValidParentheses(string s) {
            int maxLength = 0;
            stack<int> stack;
            stack.push(-1);

            // for all char in string 's'
            for (int i = 0; i < s.length(); i++) {
                // if it's opening bracket
                // push the position 'i' on to stack
                if (s[i] == '(') {
                    stack.push(i);
                }
                else {
                    // pop back if it's closing bracket
                    stack.pop();

                    // if stack is empty, we got a balance parenthesis
                    // let's push new position on stack
                    if (stack.empty()) {
                        stack.push(i);
                    }
                    else {
                        // we have a mismath, let's compare the last answer
                        // to the length of matching index
                        maxLength = max(maxLength, i - stack.top());
                    }
                }
            }

            return maxLength;
		}
	};
}

void testLongestValidParentheses() {
    cout << "Longest Valid Parentheses: " << Solution().longestValidParentheses(")()())") << endl;
}