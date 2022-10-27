/*
835. Image Overlap
https://leetcode.com/problems/image-overlap/

You are given two images, img1 and img2, represented as binary, square matrices of size n x n. 
A binary matrix has only 0s and 1s as values.

We translate one image however we choose by sliding all the 1 bits left, right, up, and/or 
down any number of units. We then place it on top of the other image. We can then calculate
the overlap by counting the number of positions that have a 1 in both images.

Note also that a translation does not include any kind of rotation. Any 1 bits that are 
translated outside of the matrix borders are erased.

Return the largest possible overlap.

Example 1:
Input: img1 = [[1,1,0],[0,1,0],[0,1,0]], img2 = [[0,0,0],[0,1,1],[0,0,1]]
Output: 3
Explanation: We translate img1 to right by 1 unit and down by 1 unit.

Example 2:

Input: img1 = [[1]], img2 = [[1]]
Output: 1
Example 3:

Input: img1 = [[0]], img2 = [[0]]
Output: 0


Constraints:
n == img1.length == img1[i].length
n == img2.length == img2[i].length
1 <= n <= 30
img1[i][j] is either 0 or 1.
img2[i][j] is either 0 or 1.
*/

using namespace std;

#include <vector>
#include <list>
#include <unordered_map>

#include <functional>
#include <utility>

namespace {
    /*
    *
    Approach 1: Shift and Count
    Algorithm

    Based on the above intuition, we could implement the solution step by step.
    First we define the function shift_and_count(x_shift, y_shift, M, R) where
    we shift the matrix M with reference to the matrix R with the shifting
    coordinate (x_shift, y_shift) and then we count the overlapping ones in
    the overlapping zone.

    1. The algorithm is organized as a loop over all possible combinations of shifting coordinates (x_shift, y_shift).
    2. More specifically, the ranges of x_shift and y_shift are both [0, N-1] where N is the width of the matrix.
    3. At each iteration, we invoke the function shift_and_count() twice to shift and count the overlapping zone,
    first with the matrix B as the reference and vice versa.

    */
    class Solution1 {
    public:

        int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
            int maxOverlaps = 0;
            int N = img1.size();

            for (int yShift = 0; yShift < N; ++yShift)
                for (int xShift = 0; xShift < N; ++xShift) {
                    // move the matrix A to the up-right and up-left directions.
                    maxOverlaps = max(
                        maxOverlaps, 
                        shiftAndCount(xShift, yShift, img1, img2)
                    );

                    // move the matrix B to the up-right and up-left directions, which is equivalent to moving A to the down-right and down-left directions 
                    maxOverlaps = max(
                        maxOverlaps, 
                        shiftAndCount(xShift, yShift, img2, img1)
                    );
                }

            return maxOverlaps;
        }

    private:
        /**
         *  Shift the matrix M in up-left and up-right directions
         *    and count the ones in the overlapping zone.
         */
        int shiftAndCount(int x_shift, int y_shift, vector<vector<int>>& M, vector<vector<int>>& R) {
            int N = M.size();

            int leftShiftCount = 0, rightShiftCount = 0;
            int rRow = 0;

            // count the cells of ones in the overlapping zone.
            for (int mRow = y_shift; mRow < N; ++mRow) {
                int rCol = 0;
                for (int mCol = x_shift; mCol < N; ++mCol) {
                    if (M[mRow][mCol] == 1 && M[mRow][mCol] == R[rRow][rCol])
                        leftShiftCount += 1;
                    if (M[mRow][rCol] == 1 && M[mRow][rCol] == R[rRow][mCol])
                        rightShiftCount += 1;
                    rCol += 1;
                }
                rRow += 1;
            }

            return max(leftShiftCount, rightShiftCount);
        }
    };

    // Linear transformation
    /*
    Algorithm: The algorithm can be implemented in two overall steps.

    - First, we filter out those non-zero cells in each matrix respectively.

    - Second, we do a cartesian product on the non-zero cells. For each pair of the products,
    we calculate the corresponding linear transformation vector as 
    V_{ab} = (X_b - X_a, Y_b - Y_a). 
    Then, we count the number of the pairs that have the same transformation vector, 
    which is also the number of ones in the overlapping zone.
    */

    // Only for pairs of std::hash-able types for simplicity.
    // You can of course template this struct to allow other hash functions
    struct pair_hash {
        template <class T1, class T2>
        std::size_t operator () (const std::pair<T1, T2>& p) const {
            auto h1 = std::hash<T1>{}(p.first);
            auto h2 = std::hash<T2>{}(p.second);

            // Mainly for demonstration purposes, i.e. works but is overly simple
            // In the real world, use sth. like boost.hash_combine
            return h1 ^ h2;
        }
    };


    using Point = pair<int, int>;

    // inline size_t key(int i,int j) {return (size_t) i << 32 | (unsigned int) j;}
    // auto hash_pair = [](const Point& p) {
    //    return (unsigned int) p.first << 31 | (unsigned int) p.second;
    // };

    // pair<int, int> p;
    // string s = to_string(p.first) + "_" + to_string(p.second);

    using Unordered_map = unordered_map<Point, int, pair_hash>;

    class Solution2 {
    protected:
        list<Point> non_zero_cells(vector<vector<int>>& M) {
            list<Point> ret;
            for (int row = 0; row < M.size(); ++row)
                for (int col = 0; col < M.size(); ++col)
                    if (M[row][col] == 1)
                        ret.push_back({ row, col });
            return ret;
        }

    public:
        int largestOverlap(vector<vector<int>>& A, vector<vector<int>>& B) {

            list<Point> A_ones = non_zero_cells(A);
            list<Point> B_ones = non_zero_cells(B);

            int maxOverlaps = 0;
            Unordered_map groupCount;

            for (Point& a : A_ones) {
                for (Point& b : B_ones) {
                    Point vec = { b.first - a.first, b.second - a.second };

                    groupCount[vec]++;
                    maxOverlaps = max(maxOverlaps, groupCount[vec]);
                }
            }
            return maxOverlaps;
        }
    };


    /*
    * Algorithm

    Overall, we enumerate all possible kernels (by shifting the matrix B), and then perform the convolution operation to count the overlapping ones. The algorithm can be broke down into the following steps:

    - First of all, we extend both the width and height of the matrix B to N + 2(N-1) = 3N-2N+2(N−1)=3N−2, and pad the extended cells with zeros, as follows:
    - From the extended and padded matrix B, we then can extract the kernel one by one.
    - For each kernel, we perform the convolution operation with the matrix A to count the number of overlapping ones.
    - At the end, we return the maximal value of overlapping ones.
    */

    class Solution3 {
    protected:
        int convolute(
            vector<vector<int>>& A,
            vector<vector<int>>& kernel,
            int xShift,
            int yShift
        ) {
            int result = 0;
            for (int row = 0; row < A.size(); ++row) {
                for (int col = 0; col < A.size(); ++col) {
                    result +=
                        A[row][col]
                        * kernel[row + yShift][col + xShift];
                }
            }

            return result;
        }

    public:
        int largestOverlap(
            vector<vector<int>>& A,
            vector<vector<int>>& B
        ) {

            int N = A.size();
            vector<vector<int>> B_padded(3 * N - 2, vector<int>(3 * N - 2, 0));

            for (int row = 0; row < N; ++row) {
                for (int col = 0; col < N; ++col) {
                    B_padded[row + N - 1][col + N - 1] = B[row][col];
                }
            }

            int maxOverlaps = 0;
            for (int xShift = 0; xShift < 2 * N - 1; ++xShift) {
                for (int yShift = 0; yShift < 2 * N - 1; ++yShift) {
                    maxOverlaps = max(
                        maxOverlaps,
                        convolute(A, B_padded, xShift, yShift)
                    );
                }
            }
            return maxOverlaps;
        }
    };
}
