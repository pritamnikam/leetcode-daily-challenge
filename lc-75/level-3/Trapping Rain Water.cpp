/*
42. Trapping Rain Water
https://leetcode.com/problems/trapping-rain-water/

Given n non-negative integers representing an elevation map where the width of each bar is 1, 
compute how much water it can trap after raining.

Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
Explanation: The above elevation map (black section) is represented
by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped.

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

namespace {
	class Solution {
	public:
		int trap(vector<int>& height) {
			vector<int> gr = findGrestesToRight(height);
			vector<int> gl = findGrestesToLeft(height);

			int waterTrapped = 0;
			for (int i = 0; i < height.size(); ++i) {
				waterTrapped += min(gr[i], gl[i]) - height[i];
			}

			return waterTrapped;
		}

	public:
		vector<int> findGrestesToLeft(vector<int>& height) {
			vector<int> gl(height.size());
			gl[0] = height[0];
			for (int i = 1; i < height.size(); ++i) {
				if (gl[i - 1] > height[i]) {
					gl[i] = gl[i - 1];
				}
				else {
					gl[i] = height[i];
				}
			}

			return gl;
		}

		vector<int> findGrestesToRight(vector<int>& height) {
			vector<int> gr(height.size());
			gr[height.size() - 1] = height[height.size() - 1];
			for (int i = height.size() - 2; i >= 0; --i) {
				if (gr[i + 1] > height[i]) {
					gr[i] = gr[i + 1];
				}
				else {
					gr[i] = height[i];
				}
			}

			return gr;
		}
	};
}

void testTrappingRainWater() {
	vector<int> height = { 0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1 };
	cout << "Trapping Rain Water: " << Solution().trap(height) << endl;
}