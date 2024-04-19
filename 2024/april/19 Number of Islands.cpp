// 200. Number of Islands
// https://leetcode.com/problems/number-of-islands

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        vector<vector<bool>> visited(grid.size(), 
                                     vector<bool>(grid[0].size(),false));
        
        int answer = 0;
        for (int sr = 0; sr < grid.size(); sr++) {
            for (int sc = 0; sc < grid[0].size(); sc++) {
                int runningTotal = 0;
                maxAreaOfIsland(grid, visited, sr, sc, runningTotal);
                if (runningTotal) {
                    ++answer;
                }
            }
        }
        
	    
	    return answer;
    }

private:
    void maxAreaOfIsland(vector<vector<char>>& grid, 
                         vector<vector<bool>>& visited,
                         int sr, int sc,
                         int& size) {
        if (sr < 0 || sr >= grid.size() || sc < 0 || sc >= grid[0].size() || 
            grid[sr][sc] != '1' || visited[sr][sc]) {
            return;
        }
        
        ++size;
        visited[sr][sc]=true;
        maxAreaOfIsland(grid, visited, sr - 1, sc, size);
        maxAreaOfIsland(grid, visited, sr + 1, sc, size);
        maxAreaOfIsland(grid, visited, sr, sc - 1, size);
        maxAreaOfIsland(grid, visited, sr, sc + 1, size);        
    }
};
