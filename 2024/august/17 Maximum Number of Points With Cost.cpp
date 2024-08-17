// 1937. Maximum Number of Points With Cost
// https://leetcode.com/problems/maximum-number-of-points-with-cost/

class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        int rows = points.size(),
            cols = points[0].size();
        vector<long long> prevRow(cols);
        // init vector
        for (int i = 0; i < cols; i++) {
            prevRow[i] = points[0][i];
        }


        for (int row = 0; row < rows - 1; row++) {
            vector<long long> leftMax(cols);
            vector<long long> rightMax(cols);
            vector<long long> currentRow(cols);

            // Calculate left-to-right maximum
            leftMax[0] = prevRow[0];
            for (int col = 1; col < cols; ++col) {
                leftMax[col] = max(leftMax[col - 1] - 1, prevRow[col]);
            }

            // Calculate right-to-left maximum
            rightMax[cols - 1] = prevRow[cols - 1];
            for (int col = cols - 2; col >= 0; --col) {
                rightMax[col] = max(rightMax[col + 1] - 1, prevRow[col]);
            }

            // Calculate the current row's maximum points
            for (int col = 0; col < cols; ++col) {
                currentRow[col] =
                    points[row + 1][col] + max(leftMax[col], rightMax[col]);
            }

            // Update previRow for the next iteration
            prevRow = currentRow;            
        }
        
        // Find the maximum value in the last processed row
        long long maxPoints = 0;
        for (int col = 0; col < cols; ++col) {
            maxPoints = max(maxPoints, prevRow[col]);
        }

        return maxPoints;
    }
};
