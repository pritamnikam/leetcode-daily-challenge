/*
84. Largest Rectangle in Histogram
https://leetcode.com/problems/largest-rectangle-in-histogram/

Given an array of integers heights representing the histogram's bar height where the width of each bar is 1, return the area of the largest rectangle in the histogram.

Example 1:
Input: heights = [2,1,5,6,2,3]
Output: 10
Explanation: The above is a histogram where width of each bar is 1.
The largest rectangle is shown in the red area, which has an area = 10 units.

Example 2:
Input: heights = [2,4]
Output: 4

Constraints:
1 <= heights.length <= 105
0 <= heights[i] <= 104


*/


using namespace std;

#include <iostream>

#include <vector>
#include <stack>

namespace {
/*
	Find the largest rectangular area possible in a given histogram
	where the largest rectangle can be made of a number of contiguous bars.

	For simplicity, assume that all bars have same width and the width is 1 unit.

		NSL (nearest smaller to left) | index
		NSR (nearest smaller to right) | index
		width := right - left -1
		area := width * height
		maxArea = max(area)
*/
	class Solution {
		vector<int> prevSmall;
		vector<int> nextSmall;

		void previousSmaller(vector<int> heights) {
			stack<int> stack;
			stack.push(0);
			prevSmall.push_back(-1);

			for (int i = 1; i < heights.size(); i++) {

				while (!stack.empty() && heights[stack.top()] >= heights[i])
					stack.pop();

				if (stack.empty()) prevSmall.push_back(-1);
				else prevSmall.push_back(stack.top());

				stack.push(i);
			}
		}

		void nextSmaller(vector<int> heights) {
			stack<int> stack;
			int n = heights.size();
			stack.push(n-1);
			prevSmall.push_back(-1);

			for (int i = n - 2; i >= 0; --i) {
				while (!stack.empty() && heights[stack.top()] >= heights[i])
					stack.pop();

				if (stack.empty()) nextSmall.push_back(n);
				else nextSmall.push_back(stack.top());

				stack.push(i);
			}

			reverse(nextSmall.begin(), nextSmall.end());
		}

	public:
		int largestRectangleArea(vector<int>& heights) {
			nextSmaller(heights);
			previousSmaller(heights);

			int largestArea = 0;

			for (int i = 0; i < heights.size(); i++) {
				int width = nextSmall[i] - prevSmall[i] - 1;
				int currentArea = width * heights[i];
				largestArea = max(largestArea, currentArea);
			}

			return largestArea;
		}
	};

}  // namespace

void testLargestRectangleArea() {
	// Input: heights = [2,1,5,6,2,3]
	// Output: 10
	vector<int>  heights = {2, 1, 5, 6, 2, 3};
	cout << "Largest Rectangle in Histogram: " << Solution().largestRectangleArea(heights) << endl;
}