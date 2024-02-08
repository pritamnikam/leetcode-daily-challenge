// 279. Perfect Squares
// https://leetcode.com/problems/perfect-squares/description/

class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n + 1, INT_MAX);

        // base case:
        dp[0] = 0;

        // pre-compute the squares
        int max_square_index = (int)sqrt(n) + 1;
        vector<int> square_numbers(max_square_index);

        for (int i = 1 ; i < max_square_index; i++) {
            square_numbers[i] = i * i;
        }


        // solve the sub-problems
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j < max_square_index; j++) {
                if (i < square_numbers[j]) break;
                dp[i] = min(
                    dp[i],
                    dp[i - square_numbers[j]] + 1
                );
            }
        }
        return dp[n];
    }
};
