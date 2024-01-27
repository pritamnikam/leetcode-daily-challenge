// 629. K Inverse Pairs Array
// https://leetcode.com/problems/k-inverse-pairs-array/
class Solution {
    const int MOD = 1000000007;
    vector<vector<int>> memo = vector<vector<int>>(1001, vector<int>(1001, 0));

public:
    int kInversePairs(int n, int k) {
        if (n == 0) return 0;
        if (k == 0) return 1;       
        
        if (memo[n][k] != 0) return memo[n][k];    
        int inv = 0;        
        for (int i = 0 ;i <= min(k, n - 1); ++i) {
            inv = (inv + kInversePairs(n-1, k-i)) % MOD;
        }
        return memo[n][k] = inv;
    }
};
