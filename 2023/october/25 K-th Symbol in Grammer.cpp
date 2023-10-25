// 779. K-th Symbol in Grammer
// https://leetcode.com/problems/k-th-symbol-in-grammar

using namespace std;

#include <iostream>
#include <vector>

namespace {

class Solution {
public:
    int kthGrammar(int n, int k) {
        int count = __builtin_popcount(k - 1);
        return (count % 2 == 0) ? 0 : 1;
    }
private:
    int dfs(int n, int k, int rootVal) {
        if (n == 1) return rootVal;
        int totalNodes = pow(2, n-1);
        if (k > totalNodes/2) {
            int nextRootVal = (rootVal == 0) ? 1 : 0;
            return dfs(n - 1, k - (totalNodes / 2), nextRootVal);
        } else {
            int nextRootVal = (rootVal == 0) ? 0 : 1;
            return dfs(n-1, k, nextRootVal);
        }
    }
};

}
