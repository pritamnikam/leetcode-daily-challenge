// 2849. Determine If a Cell Is Reachable
// https://leetcode.com/problems/determine-if-a-cell-is-reachable-at-a-given-time

using namespace std;

#include <iostream>

namespace {

class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        int width = abs(sx - fx);
        int height = abs(sy - fy);

        if (width == 0 &&
            height == 0 &&
            t == 1) {
                return false;
        }

        return t >= max(width, height);
    }
};

} // namespace
