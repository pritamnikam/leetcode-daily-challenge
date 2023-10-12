// Find in Mountain Array
// https://leetcode.com/problems/find-in-mountain-array/

using namespace std;

#include <iostream>
#include <vector>

namespace {

/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int length = mountainArr.length();

        // find peak element
        int low = 1, high = length - 2;
        while (low != high) {
            int mid = low + (high - low) / 2;
            if (mountainArr.get(mid) < mountainArr.get(mid + 1)) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }

        int peakIndex = low;

        // search in incresing part
        low = 0, high = peakIndex;
        while (low != high) {
            int mid = low + (high - low) / 2;
            if (mountainArr.get(mid) < target) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }

        if (mountainArr.get(low) == target) return low;

        // otherwise, check the stricktly decresing part
        low = peakIndex + 1, high = length - 1;
        while (low != high) {
            int mid = low + (high - low) / 2;
            if (mountainArr.get(mid) > target) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }

        if (mountainArr.get(low) == target) return low;
        return -1;
    }
};
}
