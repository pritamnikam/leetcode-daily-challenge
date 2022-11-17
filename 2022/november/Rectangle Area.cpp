/*
223. Rectangle Area
https://leetcode.com/problems/rectangle-area/

Given the coordinates of two rectilinear rectangles in a 2D plane, return the total area 
covered by the two rectangles.

The first rectangle is defined by its bottom-left corner (ax1, ay1) and its top-right corner (ax2, ay2).
The second rectangle is defined by its bottom-left corner (bx1, by1) and its top-right corner (bx2, by2).

Example 1:
Input: ax1 = -3, ay1 = 0, ax2 = 3, ay2 = 4, bx1 = 0, by1 = -1, bx2 = 9, by2 = 2
Output: 45

Example 2:
Input: ax1 = -2, ay1 = -2, ax2 = 2, ay2 = 2, bx1 = -2, by1 = -2, bx2 = 2, by2 = 2
Output: 16

Constraints:
-104 <= ax1 <= ax2 <= 104
-104 <= ay1 <= ay2 <= 104
-104 <= bx1 <= bx2 <= 104
-104 <= by1 <= by2 <= 104

*/

using namespace std;

#include <iostream>

namespace {
    class Solution {
    public:
        int computeArea(
            int ax1, int ay1, 
            int ax2, int ay2, 
            int bx1, int by1, 
            int bx2, int by2) {

            // areaOfOverlap is counted twice when in the summation of
            // areaOfA and areaOfB, so we need to subtract it from the
            // total, to get the toal area covered by both the rectangles
            int areaOfA = area(ax1, ay1, ax2, ay2);
            int areaOfB = area(bx1, by1, bx2, by2);

            return areaOfA
                + areaOfB
                - overlap(ax1, ay1, ax2, ay2, bx1, by1, bx2, by2);
        }

    private:
        int area(int x1, int y1, int x2, int y2) {
            return (x2 - x1) * (y2 - y1);
        }

        int overlap(
            int ax1, int ay1,
            int ax2, int ay2,
            int bx1, int by1,
            int bx2, int by2) {

            // calculate x overlap
            int left = max(ax1, bx1);
            int right = min(ax2, bx2);
            int xOverlap = right - left;

            // calculate y overlap
            int top = min(ay2, by2);
            int bottom = max(ay1, by1);
            int yOverlap = top - bottom;

            int areaOfOverlap = 0;

            // if the rectangles overlap each other, then calculate
            // the area of the overlap
            if (xOverlap > 0 && yOverlap > 0) {
                areaOfOverlap = xOverlap * yOverlap;
            }

            return areaOfOverlap;
        }
    };
} // namespace


void testRectangleArea() {
    /*
        Example 1:
        Input: ax1 = -3, ay1 = 0, ax2 = 3, ay2 = 4, bx1 = 0, by1 = -1, bx2 = 9, by2 = 2
        Output: 45
    */

    int ax1 = -3, ay1 = 0, ax2 = 3, ay2 = 4, bx1 = 0, by1 = -1, bx2 = 9, by2 = 2;
    cout << "Rectangle Area: " << Solution().computeArea(ax1, ay1, ax2, ay2, bx1, by1, bx2, by2) << endl;
}
