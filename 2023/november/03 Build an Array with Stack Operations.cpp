// 1441. Build an Array with Stack Operations.cpp
// https://leetcode.com/problems/build-an-array-with-stack-operations

using namespace std;

#include <iostream>
#include <vector>

namespace {
class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> ans;
        int i = 0;
        for (int num: target) {
            while (i < num - 1) {
                ans.push_back("Push");
                ans.push_back("Pop");
                i++;
            }
            ans.push_back("Push");
            i++;
        }
        return ans;
    }
};
} // namespace
