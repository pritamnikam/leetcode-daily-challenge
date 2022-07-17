/*
54. Spiral Matrix
https://leetcode.com/problems/spiral-matrix/

Given an m x n matrix, return all elements of the matrix in spiral order.

Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [1,2,3,6,9,8,7,4,5]

Input: matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
Output: [1,2,3,4,8,12,11,10,9,5,6,7]


Constraints:
m == matrix.length
n == matrix[i].length
1 <= m, n <= 10
-100 <= matrix[i][j] <= 100

*/

using namespace std;

#include <vector>

namespace {
    enum Direction {
        LEFT,
        RIGHT,
        UP,
        DOWN
    };

    enum Orientation {
        HORIZONTAL,
        VERTICAL
    };

	class Solution {
	public:
		vector<int> spiralOrder(vector<vector<int>>& matrix) {
            vector<int> answer;

            Orientation orientation = HORIZONTAL;
            Direction direction = RIGHT;

            int rows = matrix.size();
            int cols = matrix[0].size();
            int size = rows * cols;

            int count = 0;
            int i = 0, j = 0;

            int colMin = 0;
            int colMax = cols - 1;

            int rowMin = 0;
            int rowMax = rows - 1;

            while (count < size) {
                if (orientation == HORIZONTAL) {
                    if (direction == RIGHT) {
                        for (j = colMin; j <= colMax; ++j) {
                            answer.emplace_back(matrix[rowMin][j]);
                            ++count;
                        }

                        ++rowMin;
                        direction = DOWN;
                    }
                    else if (direction == LEFT) {
                        for (j = colMax; j >= colMin; --j) {
                            answer.emplace_back(matrix[rowMax][j]);
                            ++count;
                        }

                        --rowMax;
                        direction = UP;
                    }

                    orientation = VERTICAL;
                }
                
                else if (orientation == VERTICAL) {
                    if (direction == DOWN) {
                        for (i = rowMin; i <= rowMax; ++i) {
                            answer.emplace_back(matrix[i][colMax]);
                            ++count;
                        }

                        --colMax;
                        direction = LEFT;
                    }
                    else if (direction == UP) {
                        for (i = rowMax; i >= rowMin; --i) {
                            answer.emplace_back(matrix[i][colMin]);
                            ++count;
                        }

                        ++colMin;
                        direction = RIGHT;
                    }

                    orientation = HORIZONTAL;
                }
            }
            return answer;
		}
	};
}


void testSpiralOrder() {
    /*
    Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
    Output: [1,2,3,6,9,8,7,4,5]
    */
    vector<vector<int>> matrix = { {1,2,3},{4,5,6 }, { 7,8,9 } };
    vector<int> output = Solution().spiralOrder(matrix);



    /*
    Input: matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
    Output: [1,2,3,4,8,12,11,10,9,5,6,7]
    */

    matrix = { {1, 2, 3, 4 }, { 5, 6, 7, 8 }, { 9, 10, 11, 12 }};
    output = Solution().spiralOrder(matrix);
}
