// 1905. Count Sub-islands
// https://leetcode.com/problems/count-sub-islands

class Solution {
public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int rows = grid1.size();
        int cols = grid1[0].size();

        if (rows == 0 || cols == 0) return 0;
        
        int answer = 0;
        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                bool isSubIsland = true;

                if (grid2[r][c] == 1) {
                    countSubIslands(grid1, grid2, r, c, isSubIsland);
                    if (isSubIsland)
                        ++answer;
                }
            }
        }
        
        return answer;
    }
    
    vector<vector<int>> dir = { {1,0},{-1,0}, {0,1}, {0,-1} };
    
    void countSubIslands(vector<vector<int>>& grid1, 
                         vector<vector<int>>& grid2, 
                         int row, int col, 
                         bool &isSubIsland) {
        if (row < 0 || row >= grid2.size() || 
            col < 0 || col >= grid2[0].size() || 
            grid2[row][col] == 0) {
            return;
        }
        
        if (grid1[row][col] == 0)
            isSubIsland = false;
        
        grid2[row][col] = 0;
        for (auto it: dir)
            countSubIslands(grid1, grid2, 
                            row + it[0], col + it[1], 
                            isSubIsland);
    }
};
