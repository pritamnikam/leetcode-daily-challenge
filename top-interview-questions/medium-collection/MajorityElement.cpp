/*
Majority Element

Given an array nums of size n, return the majority element.

The majority element is the element that appears more than ⌊n / 2⌋ times. 
You may assume that the majority element always exists in the array.


Example 1:
Input: nums = [3,2,3]
Output: 3

Example 2:
Input: nums = [2,2,1,1,1,2,2]
Output: 2


Constraints:
n == nums.length
1 <= n <= 5 * 104
-109 <= nums[i] <= 109


Follow-up: Could you solve the problem in linear time and in O(1) space?

*/

using namespace std;

#include <vector>
#include <unordered_map>

class Solution {
public:
    // O(n) - time, O(n) - space
    int majorityElement1(vector<int>& nums) {
        unordered_map<int, int> numberCounts;
        for (int n : nums) {
            numberCounts[n]++;
        }

        int answer = 0;
        for (auto i = numberCounts.begin(); i != numberCounts.end(); ++i) {
            if (i->second > nums.size() / 2) {
                answer = i->first;
                break;
            }
        }

        return answer;
    }

    // O(nlogn) - time, O(1) - space
    int majorityElementSort(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return nums[nums.size() - 1];
    }

    // O(n) - time, O(1) - space
    // Boyer-Moore Voting Algorithm
    int majorityElement(vector<int>& nums) {
        int candidate = 0;
        int count = 0;
        for (int num : nums) {
            if (count == 0)
                candidate = num;
            if (num == candidate)
                count++;
            else
                count--;
        }
        return candidate;
    }
};