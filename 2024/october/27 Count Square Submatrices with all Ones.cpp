// 1277. Count Square Submatrices with all Ones
// https://leetcode.com/problems/count-square-submatrices-with-all-ones/

class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int rows = matrix.size(), 
            cols = matrix[0].size();

        vector<vector<int>> dp(rows + 1, vector<int>(cols + 1, 0));
        int ans = 0;

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (matrix[i][j] == 1) {
                    dp[i + 1][j + 1] = min({
                        dp[i][j + 1],
                        dp[i+1][j],
                        dp[i][j]
                    }) + 1;

                    ans += dp[i+1][j+1];
                }
            }
        }

        return ans;
    }
};
