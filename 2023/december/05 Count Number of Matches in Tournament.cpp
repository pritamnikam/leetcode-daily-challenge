// 1688. Count Number of Matches in Tournament
// https://leetcode.com/problems/count-of-matches-in-tournament/description/

class Solution {
public:
    int numberOfMatches(int n) {
        // there are |n| teams and 1 winners. Thus |n - 1| teams are eliminated.
        // to eliminate |n - 1| teams we need |n - 1| matches to be played.
        return n - 1;
    }
};
