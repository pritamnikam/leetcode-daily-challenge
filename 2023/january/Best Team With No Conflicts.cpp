/*
1626. Best Team With No Conflicts
https://leetcode.com/problems/best-team-with-no-conflicts/

You are the manager of a basketball team. For the upcoming tournament, you want to choose 
the team with the highest overall score. The score of the team is the sum of scores of all
the players in the team.

However, the basketball team is not allowed to have conflicts. A conflict exists if a younger 
player has a strictly higher score than an older player. A conflict does not occur between 
players of the same age.

Given two lists, scores and ages, where each scores[i] and ages[i] represents the score and 
age of the ith player, respectively, return the highest overall score of all possible 
basketball teams.

Example 1:
Input: scores = [1,3,5,10,15], ages = [1,2,3,4,5]
Output: 34
Explanation: You can choose all the players.

Example 2:
Input: scores = [4,5,6,5], ages = [2,1,2,1]
Output: 16
Explanation: It is best to choose the last 3 players. Notice that you are allowed to choose
multiple people of the same age.

Example 3:
Input: scores = [1,2,3,5], ages = [8,9,10,1]
Output: 6
Explanation: It is best to choose the first 3 players.

Constraints:
1 <= scores.length, ages.length <= 1000
scores.length == ages.length
1 <= scores[i] <= 106
1 <= ages[i] <= 1000

*/

using namespace std;

#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>

namespace {
    class Solution {
    public:
        int bestTeamScore(vector<int>& scores, vector<int>& ages) {
            vector<pair<int, int>> ageScorePair;
            for (int i = 0; i < scores.size(); i++) {
                ageScorePair.push_back({ scores[i], ages[i] });
            }
            // Sort in ascending order of score and then by age.
            sort(ageScorePair.begin(), ageScorePair.end());

            int highestAge = 0;
            for (int i : ages) {
                highestAge = max(highestAge, i);
            }
            vector<int> BIT(highestAge + 1, 0);

            int answer = INT_MIN;
            for (pair<int, int> ageScore : ageScorePair) {
                // Maximum score up to this age might not have all the players of this age.
                int currentBest = ageScore.first + queryBIT(BIT, ageScore.second);
                // Update the tree with the current age and its best score.
                updateBIT(BIT, ageScore.second, currentBest);

                answer = max(answer, currentBest);
            }

            return answer;
        }

    private:
        // Query tree to get the maximum score up to this age.
        int queryBIT(vector<int>& BIT, int age) {
            int maxScore = INT_MIN;
            for (int i = age; i > 0; i -= i & (-i)) {
                maxScore = max(maxScore, BIT[i]);
            }
            return maxScore;
        }


        // Update the maximum score for all the nodes with an age greater than the given age.
        void updateBIT(vector<int>& BIT, int age, int currentBest) {
            for (int i = age; i < BIT.size(); i += i & (-i)) {
                BIT[i] = max(BIT[i], currentBest);
            }
        }
    };

}  // namespace


void testBestTeamWithNoConflicts() {
    // Input: scores = [1,3,5,10,15], ages = [1,2,3,4,5], Output: 34

    vector<int> scores = { 1, 3, 5, 10, 15 }, ages = { 1, 2, 3, 4, 5 };
    cout << "Best Team With No Conflicts: " << Solution().bestTeamScore(scores, ages) << endl;
}
