/*
2007. Find Original Array From Doubled Array
https://leetcode.com/problems/find-original-array-from-doubled-array/

An integer array original is transformed into a doubled array changed by appending twice the value of every element in original, and then randomly shuffling the resulting array.

Given an array changed, return original if changed is a doubled array. If changed is not a doubled array, return an empty array. The elements in original may be returned in any order.



Example 1:

Input: changed = [1,3,4,2,6,8]
Output: [1,3,4]
Explanation: One possible original array could be [1,3,4]:
- Twice the value of 1 is 1 * 2 = 2.
- Twice the value of 3 is 3 * 2 = 6.
- Twice the value of 4 is 4 * 2 = 8.
Other original arrays could be [4,3,1] or [3,1,4].
Example 2:

Input: changed = [6,3,0,1]
Output: []
Explanation: changed is not a doubled array.
Example 3:

Input: changed = [1]
Output: []
Explanation: changed is not a doubled array.


Constraints:

1 <= changed.length <= 105
0 <= changed[i] <= 105

*/

using namespace std;

#include <vector>
#include <unordered_map>
#include <algorithm>

namespace {
    class Solution {
    public:
        vector<int> findOriginalArray(vector<int>& changed) {
            // It can't be doubled array, if the size is odd
            if (changed.size() % 2) {
                return {};
            }

            // Sort in ascending order
            sort(changed.begin(), changed.end());
            unordered_map<int, int> freq;
            // Store the frequency in the map
            for (int num : changed) {
                freq[num]++;
            }

            // if n and 2*n exists, add n to the answer
            vector<int> original;
            for (int num : changed) {
                // If element exists
                if (freq[num]) {
                    freq[num]--;
                    int twiceNum = num * 2;
                    if (freq[twiceNum] > 0) {
                        // Pair up the elements, decrement the count
                        freq[twiceNum]--;
                        // Add the original number to answer
                        original.push_back(num);
                    }
                    else {
                        return {};
                    }
                }
            }

            return original;
        }
    };
}