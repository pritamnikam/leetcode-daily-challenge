// 2558. take-gifts-from-the-richest-pile
// https://leetcode.com/problems/take-gifts-from-the-richest-pile/

class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int> heap(gifts.begin(), gifts.end());

        for (int i = 0; i < k; i++) {
            int maxElement = heap.top();
            heap.pop();

            heap.push(sqrt(maxElement));
        }

        long long remainingGifts = 0;
        while (!heap.empty()) {
            remainingGifts += heap.top();
            heap.pop();
        }

        return remainingGifts;
    }
};
