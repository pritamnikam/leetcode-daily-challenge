/*
218. The Skyline Problem
https://leetcode.com/problems/the-skyline-problem/

A city's skyline is the outer contour of the silhouette formed by 
all the buildings in that city when viewed from a distance.

Given the locations and heights of all the buildings, return the skyline
formed by these buildings collectively.

The geometric information of each building is given in the array buildings
where buildings[i] = [lefti, righti, heighti]:

lefti is the x coordinate of the left edge of the ith building.
righti is the x coordinate of the right edge of the ith building.
heighti is the height of the ith building.

You may assume all buildings are perfect rectangles grounded on an absolutely 
flat surface at height 0.

The skyline should be represented as a list of "key points" sorted by their 
x-coordinate in the form [[x1,y1],[x2,y2],...]. Each key point is the left 
endpoint of some horizontal segment in the skyline except the last point 
in the list, which always has a y-coordinate 0 and is used to mark the 
skyline's termination where the rightmost building ends. Any ground between
the leftmost and rightmost buildings should be part of the skyline's contour.

Note: There must be no consecutive horizontal lines of equal height in the 
output skyline. For instance, [...,[2 3],[4 5],[7 5],[11 5],[12 7],...] is 
not acceptable; the three lines of height 5 should be merged into one in the 
final output as such: [...,[2 3],[4 5],[12 7],...]

Example 1:
Input: buildings = [[2,9,10],[3,7,15],[5,12,12],[15,20,10],[19,24,8]]
Output: [[2,10],[3,15],[7,12],[12,0],[15,10],[20,8],[24,0]]
Explanation:
Figure A shows the buildings of the input.
Figure B shows the skyline formed by those buildings. The red points in figure B represent the key points in the output list.

Example 2:
Input: buildings = [[0,2,3],[2,5,3]]
Output: [[0,3],[5,0]]

Constraints:
1 <= buildings.length <= 104
0 <= lefti < righti <= 231 - 1
1 <= heighti <= 231 - 1
buildings is sorted by lefti in non-decreasing order.

*/

using namespace std;

#include <iostream>
#include <vector>
#include <queue>

namespace {
    class Solution {
    public:
        vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
            
            int cur = 0,
                cur_X,
                cur_H = -1,
                len = buildings.size();

            // {height, end time}
            priority_queue<pair<int, int>> liveBlg;

            vector<vector<int>> res;
            while (cur < len || !liveBlg.empty()) {
                // if either some new building is not processed 
                // or live building queue is not empty
                cur_X = liveBlg.empty()
                    ? buildings[cur][0]
                    : liveBlg.top().second; // next timing point to process

                if (cur >= len || buildings[cur][0] > cur_X) {
                    // first check if the current tallest building
                    // will end before the next timing point

                    // pop up the processed buildings, 
                    // i.e. those  have height no larger than cur_H and end 
                    // before the top one
                    while (!liveBlg.empty()
                        && (liveBlg.top().second <= cur_X)) {
                        liveBlg.pop();
                    }
                }
                else {
                    // if the next new building starts before the top one ends,
                    // process the new building in the vector
                    cur_X = buildings[cur][0];

                    while (cur < len
                        && buildings[cur][0] == cur_X) {
                        // go through all the new buildings that starts at the same point
                        // just push them in the queue
                        liveBlg.push(
                            { buildings[cur][2], buildings[cur][1] }
                        );

                        cur++;
                    }
                }

                cur_H = liveBlg.empty()
                    ? 0
                    : liveBlg.top().first; // outut the top one

                if (res.empty() || (res.back()[1] != cur_H)) {
                    res.push_back(
                        { cur_X, cur_H }
                    );
                }
            } // while
            return res;
        }
    };

}
