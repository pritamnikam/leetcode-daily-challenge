/*
473. Matchsticks to Square
https://leetcode.com/problems/matchsticks-to-square/

You are given an integer array matchsticks where matchsticks[i] is the length of the ith matchstick. 
You want to use all the matchsticks to make one square. You should not break any stick, 
but you can link them up, and each matchstick must be used exactly one time.
Return true if you can make this square and false otherwise.

Input: matchsticks = [1,1,2,2,2]
Output: true
Explanation: You can form a square with length 2, one side of the square came two sticks with length 1.

Example 2:
Input: matchsticks = [3,3,3,3,4]
Output: false
Explanation: You cannot find a way to form a square with all the matchsticks.

Constraints:
1 <= matchsticks.length <= 15
1 <= matchsticks[i] <= 108

*/

using namespace std;

#include <vector>
#include <iostream>

namespace {
  class Solution {
public:
    int n;
    int visited[16];
    
    bool possible(vector<int>& matchsticks,
                  int numsIndex,
                  int currSum,
                  int& subsetSum,
                  int k) {
        
        if(k == 1)
            return true;
        
        if(currSum == subsetSum) {
            return possible(matchsticks,
                            n-1,
                            0,
                            subsetSum,
                            k-1);
        }
        
        for(int i = numsIndex; i>=0; i--) {
            
            if(visited[i] ||
               currSum + matchsticks[i] > subsetSum)
                continue;
            
            visited[i] = 1;
            currSum   += matchsticks[i];
            
            if(possible(matchsticks,
                        i+1,
                        currSum,
                        subsetSum, k))
                return true;
            
            visited[i] = 0;
            currSum   -= matchsticks[i];
        }
        
        return false;
    }
    
    // using concept of Leetcode Problem "Partition to K Equal Sum Subsets"
    bool makesquare(vector<int>& matchsticks) {
        int sum = accumulate(begin(matchsticks),
                             end(matchsticks), 0);
        int k   = 4;
        /*
            If we are able to divide array in 4 parts each of which has equal sum (side of square)
            then it's possible to form the square with that equal subset sum as the side of square
        */
        
        if(sum % 4 != 0)
            return false;
        
        memset(visited, 0, sizeof(visited));
        
        n                   = matchsticks.size();
        int subsetSum       = sum/4;
        int numsIndex       = n-1;
        int currSum         = matchsticks[numsIndex];
        visited[numsIndex]  = 1;
        
        return possible(matchsticks,
                        numsIndex,
                        currSum,
                        subsetSum,
                        k);
    }
};
}

void testmakesquare() {
  vector<int> matchsticks = {1,1,2,2,2};
  cout << "Matchsticks to Square: " << Solution().makesquare(matchsticks) << endl; // true
  
  matchsticks = {3,3,3,3,4};
  cout << "Matchsticks to Square: " << Solution().makesquare(matchsticks) << endl; // false
}
