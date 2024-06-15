// 502. IPO
// https://leetcode.com/problems/ipo


typedef pair<int, int> pi;

class Solution {
    
    priority_queue<int> maxProfitHeap;
    priority_queue<pi, vector<pi>, greater<pi>> minCapitalHeap;

public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size(); 
        for (int i = 0; i < n; i++) {
            minCapitalHeap.push({capital[i], i});
        }

        int availableCapital = w;
        for (int i = 0; i < k; i++) {
            while (!minCapitalHeap.empty() &&
                   minCapitalHeap.top().first <= availableCapital) {
                maxProfitHeap.push(profits[minCapitalHeap.top().second]);
                minCapitalHeap.pop();
            }
            
            if (maxProfitHeap.empty())
                break;
            
            availableCapital += maxProfitHeap.top();
            maxProfitHeap.pop();
        }
        return availableCapital;
    }
};
