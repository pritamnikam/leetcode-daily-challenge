// 2225. Find player With Zero or One Losses
// https://leetcode.com/problems/find-players-with-zero-or-one-losses/description/

class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_set<int> seen;
        unordered_map<int, int> lossesCount;

        for (auto& match: matches) {
            int winner = match[0], 
                looser = match[1];

            seen.insert(winner);
            seen.insert(looser);
            lossesCount[looser]++;
        }

        // Add player with 0 or 1 loss to the corruponding list
        vector<vector<int>> answer(2, vector<int>());
        for (auto& player: seen) {
            if (lossesCount.find(player) == lossesCount.end()) {
                answer[0].push_back(player);
            } else if (lossesCount[player] == 1) {
                answer[1].push_back(player);
            }
        }

        sort(answer[0].begin(), answer[0].end());
        sort(answer[1].begin(), answer[1].end());
        return answer;
    }
};
