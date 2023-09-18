// 1337. The K Weakest Rows in a Matrix
// https://leetcode.com/problems/the-k-weakest-rows-in-a-matrix/

using namespace std;

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

struct CompareHeapElements {
    bool operator()(pair<int,int> const& p1, pair<int,int> const& p2) {
        if(p1.first == p2.first) {
            return p1.second<p2.second;
        }
        
        return p1.first < p2.first;
    }
};


class Solution {
    int getSoldersCount(vector<int>& row) {
        int l=0; int h=row.size()-1;
        while(l<=h) {
            int mid=l+(h-l)/2;
            if(row[mid]==0) {
                h=mid-1;
            } else {
                l=mid+1;
            }
        }
        return l;
    }
    
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        // {strength, row}
        priority_queue<pair<int, int>,
                       vector<pair<int, int>>,
                       CompareHeapElements> maxHeap;        
        
        for (int i = 0 ;i < mat.size(); ++i) {
            maxHeap.push({getSoldersCount(mat[i]), i});
            if (maxHeap.size() > k)
                maxHeap.pop();
        }
        
        vector<int> result;
        while (!maxHeap.empty()) {
            result.push_back(maxHeap.top().second);
            maxHeap.pop();
        }
        
        reverse(result.begin(), result.end());
        return result;
    }
};
