// 232. Implement Queue using Stack
// https://leetcode.com/problems/implement-queue-using-stacks/

class MyQueue {
    stack<int> s1, s2;
    
    void Swap(stack<int>& s1, stack<int>& s2) {
        while (!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }
    }
    
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        s1.push(x);
    }
    
    int pop() {
        Swap(s1, s2);
        int result = s2.top();
        s2.pop();
        Swap(s2, s1);
        return result;
    }
    
    int peek() {
        Swap(s1, s2);
        int result = s2.top();
        // s2.pop();
        Swap(s2, s1);
        return result;
    }
    
    bool empty() {
        return s1.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
