// 1561. Maximum Number Of Coins You Can Get
// https://leetcode.com/problems/maximum-number-of-coins-you-can-get

class Solution {
public:
    int maxCoins(vector<int>& piles) {
        // sort in ascending order
        sort(piles.begin(), piles.end());

        int answer = 0;

        // alternate pile between us and alice
        for (int i = piles.size()/3; i < piles.size(); i += 2) {
            answer += piles[i];
        }
        return answer;
    }
};
