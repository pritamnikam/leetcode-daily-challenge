// 1631. Path With Minimum Effort
// https://leetcode.com/problems/path-with-minimum-effort/

using namespace std;

#include <iostream>
#include <vector>


class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int lo = 0, hi = 1000000, answer;
        answer = hi;
        
        while (lo <= hi) {
            int mid = lo + (hi-lo)/2;
            if (dfs(heights, mid)) {
                answer = min(answer, mid);
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        
        return answer;
    }
    
    int directions[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    
    // perform DFS
    bool dfs(vector<vector<int>>& heights, int& mid) {
        int rows = heights.size(), cols = heights[0].size();
        if (rows * cols == 0)
            return false;
        
        vector<vector<int>> visited(rows, vector<int>(cols, false));
        return dfs(heights, visited, 0, 0, mid);
    }
    
    
    bool dfs(vector<vector<int>>& heights, 
             vector<vector<int>>& visited, 
             int row, int col, int& mid) {
        
        int rows = heights.size(), cols = heights[0].size();
        
        // reached the end
        if (row == rows-1 && col == cols-1)
            return true;
        
        // mark as visited
        visited[row][col] = true;
        
        for (int i = 0; i < 4; ++i) {
            int x = row + directions[i][0], y = col + directions[i][1];
            
            if (isSafe(x, y, rows, cols) && !visited[x][y]) {
                int currentDifference = abs(heights[x][y] - heights[row][col]);
                if (currentDifference <= mid) {
                    if (dfs(heights, visited, x, y, mid))
                        return true;
                }
            }
        }
        
        return false;
    }
    
    bool isSafe(int x, int y, int rows, int cols) {
        return x >= 0 && x <= rows - 1 && 
               y >= 0 && y <= cols - 1;
    }
};
