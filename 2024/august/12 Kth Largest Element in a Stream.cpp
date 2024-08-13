// 703. Kth Largest Element in a Stream
// https://leetcode.com/problems/kth-largest-element-in-a-stream

class KthLargest {
    int k_;
    priority_queue<int, vector<int>, greater<int>> pq_;
public:
    KthLargest(int k, vector<int>& nums) {
        k_ = k;
        for (int n: nums) {
            add(n);
        }
    }
    
    int add(int val) {
        pq_.push(val);
        if(pq_.size() > k_)
            pq_.pop();
        
        return pq_.top();
    }
};


/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
