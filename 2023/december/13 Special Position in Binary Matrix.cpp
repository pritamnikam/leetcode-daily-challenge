// 1582. Special Position in Binary Matrix
// https://leetcode.com/problems/special-positions-in-a-binary-matrix/

class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int rows = mat.size(), cols = mat[0].size();
        vector<int> rowCount(rows, 0);
        vector<int> colCount(cols, 0);

        for (int r = 0; r < rows; r++) {
            for (int c = 0; c< cols; c++) {
                if (mat[r][c] == 1) {
                    rowCount[r]++;
                    colCount[c]++;
                }
            }
        }
        
        int ans = 0;
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c< cols; c++) {
                if (mat[r][c] == 1) {
                    if (rowCount[r] == 1 && colCount[c] == 1)
                        ans++;
                }
            }
        }
        return ans;
    }
};
