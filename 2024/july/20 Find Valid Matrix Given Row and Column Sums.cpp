// 1695. Find Valid Matrix Given Row and Column Sums
// https://leetcode.com/problems/find-valid-matrix-given-row-and-column-sums/

class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        int N = rowSum.size(), 
            M = colSum.size();

        vector<vector<int>> originalMatrix(N, vector<int>(M, 0));
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                originalMatrix[i][j] = min(rowSum[i], colSum[j]);
                rowSum[i] -= originalMatrix[i][j];
                colSum[j] -= originalMatrix[i][j];
            }
        }
        return originalMatrix;      
    }
};
