// 1481. Find Least Number of Unique Integers after k Removals
// https://leetcode.com/problems/least-number-of-unique-integers-after-k-removals/

class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        // map to track frequencies
        unordered_map<int, int> freq;
        for (int n: arr) {
            freq[n]++;
        }

        // minheap to order by frequencies
        priority_queue<int, vector<int>, greater<int>> minHeap;

        for (auto& [key, value]: freq) {
            minHeap.push(value);
        }

        int count = 0;
        while (!minHeap.empty()) {
            count += minHeap.top();
            if (count > k) {
                return minHeap.size();
            }

            minHeap.pop();
        }

        // removed all elements
        return 0;
    }
};
