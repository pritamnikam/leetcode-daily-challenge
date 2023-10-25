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
};

}
