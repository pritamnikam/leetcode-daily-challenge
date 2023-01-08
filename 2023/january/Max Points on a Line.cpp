/*
* 149. Max Points on a Line
* https://leetcode.com/problems/max-points-on-a-line/

Given an array of points where points[i] = [xi, yi] represents a point on the X-Y plane, 
return the maximum number of points that lie on the same straight line.

Example 1:
Input: points = [[1,1],[2,2],[3,3]]
Output: 3

Example 2:
Input: points = [[1,1],[3,2],[5,3],[4,1],[2,3],[1,4]]
Output: 4

Constraints:
1 <= points.length <= 300
points[i].length == 2
-104 <= xi, yi <= 104
All the points are unique.
*/

using namespace std;

#include <iostream>
#include <vector>
#include <unordered_map>
#include <math.h>
namespace {
    class Solution {
    public:
        int maxPoints(vector<vector<int>>& points) {
            int n = points.size();
            if (n == 1) {
                return 1;
            }

            int result = 2;
            for (int i = 0; i < n; i++) {
                unordered_map<double, int> cnt;
                for (int j = 0; j < n; j++) {
                    if (j != i) {
                        cnt[atan2(points[j][1] - points[i][1], 
                            points[j][0] - points[i][0])]++;
                    }
                }
                for (auto& it : cnt) {
                    int h = it.first, 
                        count = it.second;

                    result = max(result, count + 1);
                }
            }
            return result;
        }
    };
}  // namespace

void testMaxPointsOnALine() {
    // Input: points = [[1,1],[2,2],[3,3]], Output: 3
    vector<vector<int>> points = { {1, 1},{2, 2},{3, 3} };
    cout << "Max Points on a Line: " << Solution().maxPoints(points) << endl;
}
