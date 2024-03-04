// 948. Bag of Tokens
// https://leetcode.com/problems/bag-of-tokens

class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        // sort by value
        sort(tokens.begin(), tokens.end());

        int lo = 0, hi = tokens.size()-1;
        int points = 0, answer = 0;

        // binary search
        while (lo <= hi
            && (
                power >= tokens[lo]
                || points > 0
            )
        ) {
            while (lo <= hi
                && power >= tokens[lo]
            ) {
                power -= tokens[lo];
                lo++;
                points++;
            }

            answer = max(answer, points);

            if (lo <= hi && points > 0) {
                power += tokens[hi];
                hi--;
                points--;
            }
        }

        return answer;
    }
};
