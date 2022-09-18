/*
42. Trapping Rain Water
https://leetcode.com/problems/trapping-rain-water/

Given n non-negative integers representing an elevation map where the width of 
each bar is 1, compute how much water it can trap after raining.

Example 1:
Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
Explanation: The above elevation map (black section) is represented by
array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section)
are being trapped.

Example 2:
Input: height = [4,2,0,3,2,5]
Output: 9

Constraints:
n == height.length
1 <= n <= 2 * 104
0 <= height[i] <= 105

*/

using namespace std;

#include <iostream>
#include <vector>
#include <stack>

namespace {
	class Solution {
	public:
		int trap(vector<int>& heights) {
			vector<int> gr = gretestToRight(heights), 
						gl = greatestToLeft(heights);

			int waterTrapped = 0;
			for (int i = 0; i < heights.size(); ++i) {
				waterTrapped += min(gr[i], gl[i]) - heights[i];
			}

			return waterTrapped;
		}

	private:
		vector<int> gretestToRight(vector<int>& heights) {
			vector<int> gr(heights.size());
			gr[heights.size() - 1] = heights[heights.size() - 1];
			for (int i = heights.size() - 2; i >= 0; --i) {
				if (gr[i + 1] > heights[i]) {
					gr[i] = gr[i + 1];
				}
				else {
					gr[i] = heights[i];
				}
			}
			return gr;
		}

		vector<int> greatestToLeft(vector<int>& heights) {
			vector<int> gl(heights.size());
			gl[0] = heights[0];

			for (int i = 1; i < heights.size(); ++i) {
				if (gl[i - 1] > heights[i]) {
					gl[i] = gl[i - 1];
				}
				else {
					gl[i] = heights[i];
				}
			}

			return gl;
		}
	};
}