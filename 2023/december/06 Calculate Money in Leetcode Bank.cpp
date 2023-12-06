// 1761. Calculate Money in Leetcode Bank
// https://leetcode.com/problems/calculate-money-in-leetcode-bank

class Solution {
public:
    int totalMoney(int n) {
        int k = n / 7;
        int F = 28;
        int L = 28 + (k - 1) * 7;
        int aithmaticSum = k * (F + L) / 2;

        int monday = 1 + k;
        int finalWeek = 0;
        for (int day = 0; day < n % 7; day++) {
            finalWeek += monday + day;
        }

        return aithmaticSum + finalWeek;
    }
};
