/*
1465. Maximum Area of a Piece of Cake After Horizontal and Vertical Cuts
https://leetcode.com/problems/maximum-area-of-a-piece-of-cake-after-horizontal-and-vertical-cuts/

You are given a rectangular cake of size h x w and two arrays of integers horizontalCuts and verticalCuts where:

horizontalCuts[i] is the distance from the top of the rectangular cake to the ith horizontal cut and similarly, and
verticalCuts[j] is the distance from the left of the rectangular cake to the jth vertical cut.
Return the maximum area of a piece of cake after you cut at each horizontal and vertical position provided in the arrays 
horizontalCuts and verticalCuts. Since the answer can be a large number, return this modulo 109 + 7.

*/


using namespace std;

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

namespace {
    class Solution {
    public:
        int maxArea(int h, int w,
            vector<int>& horizontalCuts,
            vector<int>& verticalCuts) {

            // Start by sorting the inputs
            sort(horizontalCuts.begin(), horizontalCuts.end());
            sort(verticalCuts.begin(), verticalCuts.end());

            int n = horizontalCuts.size();
            int m = verticalCuts.size();

            // Consider the edges first
            long maxHeight = max(horizontalCuts[0],
                h - horizontalCuts[n - 1]);

            for (int i = 1; i < n; i++) {
                // horizontalCuts[i] - horizontalCuts[i - 1] represents the distance between
                // two adjacent edges, and thus a possible height            
                maxHeight = max(maxHeight,
                    (long)horizontalCuts[i] - horizontalCuts[i - 1]);
            }

            // Consider the edges first
            long maxWidth = max(verticalCuts[0],
                w - verticalCuts[m - 1]);

            for (int i = 1; i < m; i++) {
                // verticalCuts[i] - verticalCuts[i - 1] represents the distance between
                // two adjacent edges, and thus a possible width
                maxWidth = max(maxWidth,
                    (long)verticalCuts[i] - verticalCuts[i - 1]);
            }

            // Be careful of overflow, and don't forget the modulo!
            return (int)((maxWidth * maxHeight) % (1000000007));
        }
    };
}

void testMaximumAreaOfPieceOfCakeAfterHorizontalAndVerticalCuts() {
    /*
        Input: h = 5, w = 4, horizontalCuts = [1,2,4], verticalCuts = [1,3]
        Output: 4
    */
    int h = 5, w = 4;
    vector<int> horizontalCuts = { 1, 2, 4 }, verticalCuts = { 1, 3 };
    cout << "Maximum Area of a Piece of Cake After Horizontal and Vertical Cuts: " << Solution().maxArea(h, w, horizontalCuts, verticalCuts) << endl;



    /*
        Input: h = 5, w = 4, horizontalCuts = [3,1], verticalCuts = [1]
        Output: 6
    */

    horizontalCuts = { 3, 1 }, verticalCuts = { 1 };
    cout << "Maximum Area of a Piece of Cake After Horizontal and Vertical Cuts: " << Solution().maxArea(h, w, horizontalCuts, verticalCuts) << endl;

}
