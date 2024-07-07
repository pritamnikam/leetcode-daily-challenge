// 1518. Water Bottles
// https://leetcode.com/problems/water-bottles/

class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int consumedBottles = 0;
        while (numBottles >= numExchange) {
            // Bottles will be exchanged in the current round
            int k = numBottles / numExchange;

            // cumulative sum of bottles consumed so far after this round
            consumedBottles += numExchange * k;

            // remaining filled bottles post this round
            numBottles -= numExchange * k;

            // new set of filled bottles after this round
            numBottles += k;
        }

        return consumedBottles + numBottles;
    }
};
