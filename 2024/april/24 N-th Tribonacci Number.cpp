// 1137. N-th Tribonacci Number
// https://leetcode.com/problems/n-th-tribonacci-number

class Solution {
    unordered_map<int, int> dp;
public:
    int tribonacci(int n) {
        if (dp.count(n)) return dp[n];
        if (n < 2) return n;
        if (n == 2) return 1;
        return dp[n] = 
            tribonacci(n-1) + 
            tribonacci(n-2) + 
            tribonacci(n-3);
    }
};
