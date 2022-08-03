/*
Subsets

Given an integer array nums of unique elements, return all possible subsets (the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.



Example 1:

Input: nums = [1,2,3]
Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
Example 2:

Input: nums = [0]
Output: [[],[0]]


Constraints:

1 <= nums.length <= 10
-10 <= nums[i] <= 10
All the numbers of nums are unique.

*/

using namespace std;

#include <vector>

class Solution {

    void dfs(vector<int>& nums,
            int index,
            vector<int>& cur,
            vector<vector<int>>& result) {
        // base case:
        if (index >= nums.size()) {
            result.push_back(cur);
            return;
        }

        // Decision to add the current element and recurse.
        cur.push_back(nums[index]);
        dfs(nums, index + 1, cur, result);

        // Decision to remove the current element and recurse.
        cur.pop_back();
        dfs(nums, index + 1, cur, result);
    }

public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        if (nums.size() < 1) {
            return result;
        }

        vector<int> cur;
        dfs(nums, 0, cur, result);
        return result;
    }
};