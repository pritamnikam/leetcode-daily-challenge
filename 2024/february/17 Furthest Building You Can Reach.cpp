// 1642. Furthest Building You Can Reach
// https://leetcode.com/problems/furthest-building-you-can-reach


class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        // max heap
        priority_queue<int> bricksAllocation;
        for (int i = 0; i < heights.size() - 1; i++) {
            // number of bricks required to climb to next building
            int bricksRequiredToClimbNext = heights[i + 1] - heights[i];
            if (bricksRequiredToClimbNext <= 0) {
                continue;
            }

            bricksAllocation.push(bricksRequiredToClimbNext);
            bricks -= bricksRequiredToClimbNext;

            // exhausted all bricks and laddrs
            if (bricks < 0 && ladders == 0) {
                return i;
            }

            // we still have ladders
            if (bricks < 0) {
                bricks += bricksAllocation.top();
                bricksAllocation.pop();

                ladders--;
            }
        }

        // we finished climbing all buildings
        return heights.size() - 1;
    }
};
