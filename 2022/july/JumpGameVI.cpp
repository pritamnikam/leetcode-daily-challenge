/*
1696. Jump Game VI
https://leetcode.com/problems/jump-game-vi/

You are given a 0-indexed integer array nums and an integer k.
You are initially standing at index 0. In one move, you can jump at most k steps forward without 
going outside the boundaries of the array. That is, you can jump from index i to any index in the
range [i + 1, min(n - 1, i + k)] inclusive.
You want to reach the last index of the array (index n - 1). Your score is the sum of all nums[j]
for each index j you visited in the array.
Return the maximum score you can get.

Example 1:
Input: nums = [1,-1,-2,4,-7,3], k = 2
Output: 7
Explanation: You can choose your jumps forming the subsequence [1,-1,4,3] (underlined above). The sum is 7.

Example 2:
Input: nums = [10,-5,-2,4,0,3], k = 3
Output: 17
Explanation: You can choose your jumps forming the subsequence [10,4,3] (underlined above). The sum is 17.

Example 3:
Input: nums = [1,-5,-20,4,-1,3,-6,-3], k = 2
Output: 0

Constraints:
1 <= nums.length, k <= 105
-104 <= nums[i] <= 104

*/

#include <vector>
#include <queue>
#include <deque>

using namespace std;

namespace {
class Solution {
public:
    int maxResult1(vector<int>& nums, int k) {
        int n = nums.size();
        
        // Step 1: Initialize a dp array score, where score[i] represents the max score starting at nums[0] and ending at nums[i].
        vector<int> score(n);
        score[0] = nums[0];
        
        // Step 2: Initialize a deque array dq storing indexes of nums such that the corresponding values are monotonically decreasing.
        deque<int> dq;
        dq.push_back(0);
        
        // Step 3: Iterate over nums. For each element nums[i]:
        for (int i = 1; i < n; ++i) {
            // Pop all the indexes smaller than i-k out of dq from left.
            while (!dq.empty() && dq.front() < i - k) {
                dq.pop_front();
            }
            
            // Update score[i] to score[dq.peekFirst()] + nums[i].
            score[i] = score[dq.front()] + nums[i];
            
            // If the corresponding score of the rightmost index in dq (i.e., score[dq.peekLast()]) is smaller than score[i],
            // pop it from the right to make corresponding values monotonically decreasing. Repeat.
            while (!dq.empty() && score[i] >= score[dq.back()]) {
                dq.pop_back();
            }
            
            // Push i into the right of dq.
            dq.push_back(i);
        }
        
        return score[n - 1];
    }
    
    
    int maxResult(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> score(n);
        score[0] = nums[0];
        
        priority_queue<pair<int, int>> maxHeap;
        maxHeap.push({nums[0], 0});
        
        for (int i = 1; i< n; ++i) {
            while (maxHeap.top().second < i - k)
                maxHeap.pop();
            
            score[i] = nums[i] + score[maxHeap.top().second];
            maxHeap.push({score[i], i});
        }
        
        return score[n-1];
    }
};

} // namespace

void testJumpGameVI() {
  vector<int> nums = {1,-1,-2,4,-7,3};
  int k = 2;
  
  cout << "Jump Game VI maximum score: " << Solution().maxResult(nums, k) << endl; // 7
  
  
  nums = {10,-5,-2,4,0,3};
  k = 3;
  cout << "Jump Game VI maximum score: " << Solution().maxResult(nums, k) << endl;  // 17
  
}

