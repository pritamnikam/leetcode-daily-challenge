/*
Permutations

Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.



Example 1:

Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
Example 2:

Input: nums = [0,1]
Output: [[0,1],[1,0]]
Example 3:

Input: nums = [1]
Output: [[1]]


Constraints:

1 <= nums.length <= 6
-10 <= nums[i] <= 10
All the integers of nums are unique.


*/

using namespace std;

#include <vector>

class Solution {
public:
    /*
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> answer;
        vector<int> cur = nums;
        answer.push_back(cur);

        while(true) {
            next_permutation(cur.begin(), cur.end());
            if(nums == cur) {
                break;
            }

            answer.push_back(cur);
        }

        return answer;
    }
    */

    /*
    vector<vector<int>> permute(vector<int>& nums) {
        if (nums.size() <= 1) {
            return {nums};
        }

        vector<vector<int>> result;
        for (int i = 0; i< nums.size(); ++i) {
            // erase number at ith  position
            vector<int> vt(nums.begin(), nums.end());
            vt.erase(i + vt.begin());

            // get the permutations for remaining array
            auto permutations = permute(vt);

            // restore the number back to its position in received permutations
            for (int j = 0; j < permutations.size(); ++j) {
                vector<int> v = permutations[j];
                v.insert(v.begin(), nums[i]);

                // add to final result
                result.push_back(v);
            }
        }

        // resturn the result
        return result;
    }

    */
    vector<vector<int>> permute2(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> currentPermutation;
        generatePermutationsRecursive(nums, result, 0, currentPermutation);
        return result;
    }

    void generatePermutationsRecursive(vector<int>& nums,
        vector<vector<int>>& result,
        int index,
        vector<int>& currentPermutation) {
        if (index == nums.size()) {
            result.push_back(currentPermutation);
        }
        else {
            // create a new permutation by adding the current number at every position
            for (int i = 0; i <= currentPermutation.size(); i++) {
                vector<int> newPermutation(currentPermutation);
                newPermutation.insert(newPermutation.begin() + i, nums[index]);
                generatePermutationsRecursive(nums, result, index + 1, newPermutation);
            }
        }
    }


    vector<vector<int>> permute(vector<int>& nums) {
        if (nums.size() <= 1) {
            return { nums };
        }

        vector<vector<int>> result;
        for (int i = 0; i < nums.size(); ++i) {
            // 1. erase number at ith  position
            vector<int> vt(nums.begin(), nums.end());
            vt.erase(i + vt.begin());

            // 2. get permutation for remaining numbers
            vector<vector<int>> permutations = permute(vt);

            // 3. restore the number back to its position in received permutations
            for (int j = 0; j < permutations.size(); ++j) {
                vector<int> v = permutations[j];
                v.insert(v.begin(), nums[i]);

                // add to final result
                result.push_back(v);
            }
        }
        return result;
    }
};