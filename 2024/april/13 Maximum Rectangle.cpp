// 85. Maximum Rectangle
// https://leetcode.com/problems/maximal-rectangle

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.size() == 0) return 0;
        
        int maxArea = 0, rows = matrix.size(), cols = matrix[0].size();
        vector<int> dp(cols, 0);

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                // Update the state of this row's histogram using the last row's histogram
                // by keeping track of the number of consecutive ones
                dp[j] = (matrix[i][j] == '1')
                    ? dp[j] + 1
                    : 0; 
            }

            // Update max area with the maximum area from this row's histogram
            maxArea = max(
                maxArea,
                largestRectangleArea(dp)
            );
        }

        return maxArea;
    }

private:
    int largestRectangleArea(
        vector<int>& heights
    ) {
        stack<int> stack;
        stack.push(-1);

        int maxArea = 0;
        for (int i = 0; i < heights.size(); i++) {
            while(
                stack.top() != -1 &&
                heights[stack.top()] >= heights[i]
            ) {
                int currentHeight = heights[stack.top()];
                stack.pop();

                int currentWidth = i - stack.top() - 1;
                maxArea = max(
                    maxArea,
                    currentHeight * currentWidth
                );
            }

            stack.push(i);
        }

        while (stack.top() != -1) {
                int currentHeight = heights[stack.top()];
                stack.pop();

                int currentWidth = heights.size() - stack.top() - 1;
                maxArea = max(
                    maxArea,
                    currentHeight * currentWidth
                );
        }

        return maxArea;
    }
};
