/*
155. Min Stack
https://leetcode.com/problems/min-stack/

Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

Implement the MinStack class:

MinStack() initializes the stack object.
void push(int val) pushes the element val onto the stack.
void pop() removes the element on the top of the stack.
int top() gets the top element of the stack.
int getMin() retrieves the minimum element in the stack.
You must implement a solution with O(1) time complexity for each function.



Example 1:

Input
["MinStack","push","push","push","getMin","pop","top","getMin"]
[[],[-2],[0],[-3],[],[],[],[]]

Output
[null,null,null,null,-3,null,0,-2]

Explanation
MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin(); // return -3
minStack.pop();
minStack.top();    // return 0
minStack.getMin(); // return -2


Constraints:

-231 <= val <= 231 - 1
Methods pop, top and getMin operations will always be called on non-empty stacks.
At most 3 * 104 calls will be made to push, pop, top, and getMin.

*/

using namespace std;

#include <iostream>
#include <stack>

namespace {
    class MinStack {
        stack<int> st;    // stack to hold values
        stack<int> stMin; // auxiliary stack to maintain minimum so far
    public:
        MinStack() {

        }

        void push(int val) {
            // push to auxiliary stack either:
            // 1. stack is empty or 
            // 2. top of stack is bigger than the val.
            if (stMin.empty() || stMin.top() >= val)
                stMin.push(val);

            st.push(val);
        }

        void pop() {
            if (st.empty())
                return;

            // pop from auxiliary stack if top of stack is same as that of auxiliary stack
            if (st.top() == stMin.top())
                stMin.pop();

            st.pop();
        }

        int top() {
            return st.top();
        }

        int getMin() {
            return stMin.top();
        }
    };
}