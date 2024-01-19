// 931. Minimum Falling Path Sum
// https://leetcode.com/problems/minimum-falling-path-sum


class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size(),
            m = matrix[0].size();

        int answer = INT_MAX;

        for (int row = n- 2; row >= 0; row--) {
            for (int col = 0; col < m; col++) {
                int down = INT_MAX,
                    leftDown = INT_MAX,
                    rightDown = INT_MAX;

                down = matrix[row + 1][col];
                if (col > 0) {
                    leftDown = matrix[row + 1][col - 1];
                }

                if (col < m - 1) {
                    rightDown = matrix[row + 1][col + 1];
                }

                matrix[row][col] += min({down, leftDown, rightDown});
            }
        }


        for (int col = 0; col < m; col++) {
            answer = min(answer, matrix[0][col]);
        }

        return answer;
    }
};
