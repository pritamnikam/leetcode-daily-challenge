// 34. Find First and Last Position of the Element in the Sorted Array
// https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/

using namespace std;

#include <iostream>
#include <vector>

namespace {

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.size() == 0 || target > nums.back() || target < nums.front()) {
            return { -1, -1 };
        }

        int first = findFirst(nums, target);
        if (first == -1)
            return { -1, -1 };

        return { first, findLast(nums, target) };
    }

private:
int findFirst(vector<int>& nums, int target) {
        int answer = -1;
        int start = 0, end = nums.size()-1;
        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (nums[mid] == target) {
                answer = mid;
                end = mid - 1;
            }
            else if (nums[mid] < target) {
                start = mid + 1;
            }
            else {
                end = mid - 1;
            }
        }

        return answer;
    }

    int findLast(vector<int>& nums, int target) {
        int answer = -1;
        int start = 0, end = nums.size()-1;
        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (nums[mid] == target) {
                answer = mid;
                start = mid + 1;
            }
            else if (nums[mid] < target) {
                start = mid + 1;
            }
            else {
                end = mid - 1;
            }
        }

        return answer;
    }
};

}
