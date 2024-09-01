// 2022 Convert 1D array into 2D array
// https://leetcode.com/problems/convert-1d-array-into-2d-array

class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        // Check if it is possible to form an m x n 2D array
        if (m * n != original.size()) {
            // If not, return an empty 2D array
            return vector<vector<int>>(0, vector<int>(0));
        }

        // Initialize the result 2D array with m rows and n columns
        vector<vector<int>> resultArray(m, vector<int>(n));

        // Fill the 2D array with elements from the original array
        for (int i = 0; i < original.size(); i++) {
            resultArray[i / n][i % n] = original[i];
        }


        return resultArray;
    }
};
