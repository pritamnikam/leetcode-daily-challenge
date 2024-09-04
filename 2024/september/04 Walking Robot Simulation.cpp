// 874. Walking Robot Simulation
// https://leetcode.com/problems/walking-robot-simulation/


class Solution {
private:
    const int kHashMultiplier = 60001;
    int hashCoordinates(int x, int y) { return x + kHashMultiplier*y; }
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        unordered_set<int> obstaclesSet;
        for (auto& ob: obstacles) {
            obstaclesSet.insert(
                hashCoordinates(
                    ob[0], ob[1]
                )
            );
        }

        vector<vector<int>> dir = {
            {0,1}, {1,0},{0,-1},{-1,0}
        };

        vector<int> currentPosition = {0, 0};
        int maxDistanceSquared = 0;
        int currentDirection = 0; // 0 - north, 1: East, 2: South, 3: West

        for (int cmd: commands) {
            if (cmd == -1) {
                // turn right
                currentDirection = (currentDirection + 1) % 4;
                continue;
            }

            if (cmd == -2) {
                // Turn left
                currentDirection = (currentDirection + 3) % 4;
                continue;
            }

            // move forward
            vector<int> direction = dir[currentDirection];
            for (int step = 0; step < cmd; step++) {
                int nextX = currentPosition[0] + direction[0];
                int nextY = currentPosition[1] + direction[1];

                if (
                    obstaclesSet.contains(
                        hashCoordinates(
                            nextX, nextY
                        )
                    )
                ) {
                    break;
                }

                currentPosition[0] = nextX;
                currentPosition[1] = nextY;
            }
            maxDistanceSquared =
                max(maxDistanceSquared,
                    currentPosition[0] * currentPosition[0] +
                        currentPosition[1] * currentPosition[1]);

        }
        return maxDistanceSquared;
    }
};
