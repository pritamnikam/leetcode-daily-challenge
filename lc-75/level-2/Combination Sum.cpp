/*
39. Combination Sum

https://leetcode.com/problems/combination-sum/

Given an array of distinct integers candidates and a target integer target, return a list of all unique 
combinations of candidates where the chosen numbers sum to target. You may return the combinations in any order.

The same number may be chosen from candidates an unlimited number of times. Two combinations are unique if the
frequency of at least one of the chosen numbers is different.

It is guaranteed that the number of unique combinations that sum up to target is less than 150 combinations for
the given input.



Example 1:
Input: candidates = [2,3,6,7], target = 7
Output: [[2,2,3],[7]]
Explanation:
2 and 3 are candidates, and 2 + 2 + 3 = 7. Note that 2 can be used multiple times.
7 is a candidate, and 7 = 7.
These are the only two combinations.

Example 2:
Input: candidates = [2,3,5], target = 8
Output: [[2,2,2,2],[2,3,3],[3,5]]

Example 3:
Input: candidates = [2], target = 1
Output: []


Constraints:
1 <= candidates.length <= 30
1 <= candidates[i] <= 200
All elements of candidates are distinct.
1 <= target <= 500

*/

using namespace std;

#include <vector>
#include <iostream>
#include <algorithm>

namespace {
    class Solution {
        void Backtrack(vector<int>& candidates,
            int target,
            int index,
            vector<vector<int>>& result,
            vector<int>& cur) {
            // Base Cases :
            // a. If the sum == 0, at any moment in the recursive calls, 
            // we add that list to the result list and return from the function.
            if (target == 0) {
                result.push_back(cur);
                return;
            }

            // b. If the sum becomes negative or we reach the end of the array, 
            // we terminate that recursive call and return from that call.
            else if (target < 0 || index == candidates.size())
                return;

            // Recurrsion:
            // 1. with the current element in the list
            cur.push_back(candidates[index]);
            Backtrack(candidates, target - candidates[index], index, result, cur);

            // 2. without current element in the list
            cur.pop_back();
            Backtrack(candidates, target, index + 1, result, cur);
        }


        vector<int> sortAndRemoveDuplicates(vector<int>& candidates) {
            // 1. sort input
            sort(candidates.begin(), candidates.end());

            // 2. remove duplicates
            vector<int> input;
            input.push_back(candidates[0]);
            for (int i = 1; i < candidates.size(); ++i) {
                if (candidates[i] == candidates[i - 1])
                    continue;

                input.push_back(candidates[i]);
            }

            return input;
        }

    public:
        vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
            vector<int> input = sortAndRemoveDuplicates(candidates);

            // Backtrack
            vector<vector<int>> result;
            vector<int> cur;
            Backtrack(input, target, 0, result, cur);
            return result;
        }
    };
}