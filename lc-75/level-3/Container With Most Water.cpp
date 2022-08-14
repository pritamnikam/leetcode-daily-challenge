/*
11. Container With Most Water
https://leetcode.com/problems/container-with-most-water/

You are given an integer array height of length n. There are n vertical lines drawn 
such that the two endpoints of the ith line are (i, 0) and (i, height[i]).

Find two lines that together with the x-axis form a container, such that the container 
contains the most water.

Return the maximum amount of water a container can store.

Notice that you may not slant the container.

Input: height = [1,8,6,2,5,4,8,3,7]
Output: 49
Explanation: The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. 
In this case, the max area of water (blue section) the container can contain is 49.


Input: height = [1,1]
Output: 1


Constraints:

n == height.length
2 <= n <= 105
0 <= height[i] <= 104

*/

using namespace std;

#include <iostream>
#include <vector>


namespace {
	class Solution {

	public:
		int maxArea(vector<int>& height) {
			int area = INT_MIN;
			int n = height.size();
			int l = 0, r = n - 1;

			while (l < r) {
				int currentArea = min(height[r], height[l]) * (r - l);
				area = max(area, currentArea);

				if (height[l] < height[r]) ++l;
				else --r;
			}

			return area;
		}
	};
} // namespace


void testContainerWithMostWater() {
	// height = [1, 8, 6, 2, 5, 4, 8, 3, 7], Output: 49
	vector<int> height = { 1, 8, 6, 2, 5, 4, 8, 3, 7 };
	cout << "Container With Most Water: " << Solution().maxArea(height) << endl;
}