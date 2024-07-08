// 1823. Find the Winner of the Circular Game
// https://leetcode.com/problems/find-the-winner-of-the-circular-game/

class Solution {
public:
    int findTheWinner(int n, int k) {
        return winnerHelper(n, k) + 1;
    }
    // iterative
    int findTheWinner2(int n, int k) {
        int ans = 0;
        for (int i = 2; i <= n; i++) {
            ans = (ans + k) % i;
        }
        // add 1 to convert back to 1 indexing
        return ans + 1;
    }
private:
    int winnerHelper(int n, int k) {
        if (n == 1) return 0;
        return (winnerHelper(n - 1, k) + k) % n;
    }
};
