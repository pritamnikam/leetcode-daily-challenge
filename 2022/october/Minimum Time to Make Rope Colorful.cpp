/*
1578. Minimum Time to Make Rope Colorful
https://leetcode.com/problems/minimum-time-to-make-rope-colorful/

Alice has n balloons arranged on a rope. You are given a 0-indexed string 
colors where colors[i] is the color of the ith balloon.

Alice wants the rope to be colorful. She does not want two consecutive balloons
to be of the same color, so she asks Bob for help. Bob can remove some balloons 
from the rope to make it colorful. You are given a 0-indexed integer array
neededTime where neededTime[i] is the time (in seconds) that Bob needs to 
remove the ith balloon from the rope.

Return the minimum time Bob needs to make the rope colorful.

Example 1:
Input: colors = "abaac", neededTime = [1,2,3,4,5]
Output: 3
Explanation: In the above image, 'a' is blue, 'b' is red, and 'c' is green.
Bob can remove the blue balloon at index 2. This takes 3 seconds.
There are no longer two consecutive balloons of the same color. Total time = 3.

Example 2:
Input: colors = "abc", neededTime = [1,2,3]
Output: 0
Explanation: The rope is already colorful. Bob does not need to remove any balloons from the rope.

Example 3:
Input: colors = "aabaa", neededTime = [1,2,3,4,1]
Output: 2
Explanation: Bob will remove the ballons at indices 0 and 4. Each ballon takes 1 second to remove.
There are no longer two consecutive balloons of the same color. Total time = 1 + 1 = 2.


Constraints:
n == colors.length == neededTime.length
1 <= n <= 105
1 <= neededTime[i] <= 104
colors contains only lowercase English letters.
*/

using namespace std;

#include <iostream>
#include <string>
#include <vector>

namespace {
    class Solution {
    public:
        // 2-pointers approach: Sliding window
        int minCost1(string colors, vector<int>& neededTime) {
            int totlaTime = 0, left = 0, right = 0, n = neededTime.size();

            while (left < n and right < n) {
                int currentTime = 0, 
                    currentMax = 0;

                while (right < n 
                    and colors[left] == colors[right]) {
                    currentTime += neededTime[right];
                    currentMax = max(currentMax, neededTime[right]);
                    ++right;
                }

                totlaTime += (currentTime - currentMax);
                left = right;
            }

            return totlaTime;
        }

        // 1-pass solution
        int minCost(string colors, vector<int>& neededTime) {
            int currentMaxTime = 0, 
                totalTime = 0,
                n = neededTime.size();

            for (int i = 0; i < n; ++i) {
                if (i > 0
                    and colors[i] != colors[i - 1]) {
                    currentMaxTime = 0;
                }

                // Increment totalTime by the smaller one.
                // Update currMaxTime as the larger one.
                totalTime += min(currentMaxTime, neededTime[i]);
                currentMaxTime = max(currentMaxTime, neededTime[i]);
            }

            return totalTime;
        }
    };
}  // namespace

void testMinimumTimeToMakeRopeColorful() {
    // colors = "aabaa", neededTime = [1,2,3,4,1]
    string colors = "aabaa";
    vector<int> neededTime = { 1,2,3,4,1 };
    cout << "Minimum Time to Make Rope Colorful: " << Solution().minCost(colors, neededTime) << endl;
}
