/*
1473. Paint House III
https://leetcode.com/problems/paint-house-iii/

There is a row of m houses in a small city, each house must be painted with one of the n colors (labeled from 1 to n), 
some houses that have been painted last summer should not be painted again.

A neighborhood is a maximal group of continuous houses that are painted with the same color.

For example: houses = [1,2,2,3,3,2,1,1] contains 5 neighborhoods [{1}, {2,2}, {3,3}, {2}, {1,1}].
Given an array houses, an m x n matrix cost and an integer target where:

houses[i]: is the color of the house i, and 0 if the house is not painted yet.
cost[i][j]: is the cost of paint the house i with the color j + 1.
Return the minimum cost of painting all the remaining houses in such a way that there are exactly 
target neighborhoods. If it is not possible, return -1.

Example 1:
Input: houses = [0,0,0,0,0], cost = [[1,10],[10,1],[10,1],[1,10],[5,1]], m = 5, n = 2, target = 3
Output: 9
Explanation: Paint houses of this way [1,2,2,1,1]
This array contains target = 3 neighborhoods, [{1}, {2,2}, {1,1}].
Cost of paint all houses (1 + 1 + 1 + 1 + 5) = 9.

Example 2:
Input: houses = [0,2,1,2,0], cost = [[1,10],[10,1],[10,1],[1,10],[5,1]], m = 5, n = 2, target = 3
Output: 11
Explanation: Some houses are already painted, Paint the houses of this way [2,2,1,2,2]
This array contains target = 3 neighborhoods, [{2,2}, {1}, {2,2}]. 
Cost of paint the first and last house (10 + 1) = 11.

Example 3:
Input: houses = [3,1,2,3], cost = [[1,1,1],[1,1,1],[1,1,1],[1,1,1]], m = 4, n = 3, target = 3
Output: -1
Explanation: Houses are already painted with a total of 4 neighborhoods [{3},{1},{2},{3}] different of target = 3.

Constraints:
m == houses.length == cost.length
n == cost[i].length
1 <= m <= 100
1 <= n <= 20
1 <= target <= m
0 <= houses[i] <= n
1 <= cost[i][j] <= 104

*/

namespace {
  class Solution1 {
    unordered_map<string, int> dp; // int memo[100][100][21];
    
    // Maximum cost possible plus 1
    const int MAX_COST = 1000001;
    
public:
    int minCost(vector<int>& houses,
                vector<vector<int>>& cost,
                int m, int n, int target) {
        int answer = minCost(houses, cost, target, 0, 0, 0);
        return answer == MAX_COST ? -1 : answer;
    }
    
private:
    // i -> house index, 
    // j -> neibhour count, 
    // k -> color
    int minCost(vector<int>& houses,
                vector<vector<int>>& cost,
                int target,
                int i, int j, int k) {
                        
        // If all houses are traversed, check if the neighbor count is as expected or not
        if (i == houses.size()) return j==target ? 0 : MAX_COST;
        
        // If the neighborhoods are more than the threshold, we can't have target neighborhoods
        if (j > target) return MAX_COST;
        
        // Alrady have answer for the sub-problem
        string key = to_string(i) + "-" +
                     to_string(j) + "-" + 
                     to_string(k);
        if (dp.count(key)) return dp[key];
        
        int newCost = MAX_COST;
        
        // If the house is already painted, update the values accordingly
        if (houses[i]) {
            int new_j = j + (houses[i] != k);
            newCost = minCost(houses, cost, target,
                              1 + i, new_j, houses[i]);
        } else {
            int totalColors = cost[0].size();
            
            // If the house is not painted, try every possible color and store the minimum cost
            for (int color = 1; color <= totalColors; color++) {
                int new_j = j + (color != k);
                int currCost = cost[i][color - 1] + 
                               minCost(houses, cost, target,
                                       1 + i, new_j, color);
                newCost = min(newCost, currCost);
            }
        }
        
        // Return the minimum cost and also storing it for future reference (memoization)
        return dp[key] = newCost;
    }
};
}
