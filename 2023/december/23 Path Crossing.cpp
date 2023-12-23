// 1496. Path Crossing
// https://leetcode.com/problems/path-crossing

class Solution {
public:
    bool isPathCrossing(string path) {
        unordered_map<char, pair<int, int>> moves;
        moves['N'] = {0, 1};
        moves['S'] = {0, -1};
        moves['W'] = {-1, 0};
        moves['E'] = {1, 0};

        unordered_set<string> visited;
        visited.insert("0,0");

        int x = 0, y = 0;

        for (char ch: path) {
            x += moves[ch].first;
            y += moves[ch].second;

            string hash = to_string(x) + "," + to_string(y);
            if (visited.find(hash) != visited.end()) return true;
            visited.insert(hash);
        }
        return false;
    }
};
