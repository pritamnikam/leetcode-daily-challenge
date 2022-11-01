/*
766. Toeplitz Matrix
https://leetcode.com/problems/toeplitz-matrix/
*/

namespace {
  class Solution {
  public:
      bool isToeplitzMatrix(vector<vector<int>>& matrix) {
          unordered_map<int, int> groups;
          for (int r = 0; r < matrix.size(); ++r) {
              for (int c = 0; c < matrix[0].size(); ++c) {
                  if (!groups.count(r-c)) {
                      groups[r-c] = matrix[r][c];
                  } else if (groups[r-c] != matrix[r][c]) {
                      return false;
                  }
              }
          }
          return true;
      }
  };
} // namespace
