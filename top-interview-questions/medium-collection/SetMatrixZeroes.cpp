/*

Set Matrix Zeroes


Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's.

You must do it in place.

Example 1:
Input: matrix = [[1,1,1],[1,0,1],[1,1,1]]
Output: [[1,0,1],[0,0,0],[1,0,1]]

Input: matrix = [[0,1,2,0],[3,4,5,2],[1,3,1,5]]
Output: [[0,0,0,0],[0,4,5,0],[0,3,1,0]]

Follow up:

A straightforward solution using O(mn) space is probably a bad idea.
A simple improvement uses O(m + n) space, but still not the best solution.
Could you devise a constant space solution?

Constraints:

m == matrix.length
n == matrix[0].length
1 <= m, n <= 200
-231 <= matrix[i][j] <= 231 - 1

*/

using namespace std;

#include <vector>
#include <queue>
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();

        queue<pair<int, int>> queue;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (matrix[i][j] == 0) {
                    queue.push({ i, j });
                }
            }
        }

        while (!queue.empty()) {
            pair<int, int> cell = queue.front();
            queue.pop();

            for (int i = 0; i < rows; ++i) {
                matrix[i][cell.second] = 0;
            }

            for (int i = 0; i < cols; ++i) {
                matrix[cell.first][i] = 0;
            }
        }
    }
};

#include <unordered_set>

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();

        unordered_set<int> rSet;
        unordered_set<int> cSet;

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (matrix[i][j] == 0) {
                    if (!rSet.count(i)) {
                        rSet.insert(i);
                    }

                    if (!cSet.count(j)) {
                        cSet.insert(j);
                    }
                }
            }
        }


        for (int r : rSet) {
            for (int i = 0; i < cols; ++i)
                matrix[r][i] = 0;
        }

        for (int c : cSet) {
            for (int i = 0; i < rows; ++i)
                matrix[i][c] = 0;
        }
    }
};