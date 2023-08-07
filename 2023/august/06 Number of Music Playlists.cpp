/*
920. Number of Music Playlists
https://leetcode.com/problems/number-of-music-playlists/description/

Your music player contains n different songs. You want to listen to goal songs (not necessarily different) during your trip. To avoid boredom, you will create a playlist so that:

Every song is played at least once.
A song can only be played again only if k other songs have been played.
Given n, goal, and k, return the number of possible playlists that you can create. Since the answer can be very large, return it modulo 109 + 7.



Example 1:

Input: n = 3, goal = 3, k = 1
Output: 6
Explanation: There are 6 possible playlists: [1, 2, 3], [1, 3, 2], [2, 1, 3], [2, 3, 1], [3, 1, 2], and [3, 2, 1].
Example 2:

Input: n = 2, goal = 3, k = 0
Output: 6
Explanation: There are 6 possible playlists: [1, 1, 2], [1, 2, 1], [2, 1, 1], [2, 2, 1], [2, 1, 2], and [1, 2, 2].
Example 3:

Input: n = 2, goal = 3, k = 1
Output: 2
Explanation: There are 2 possible playlists: [1, 2, 1] and [2, 1, 2].


Constraints:

0 <= k < n <= goal <= 100
*/

using namespace std;

#include <iostream>
#include <vector>

namespace {
    class Solution {
    public:
        int numMusicPlaylists(int n, int goal, int k) {
            const int MOD = 1e9 + 7;

            // Initialize the DP table
            vector<vector<long>> dp(goal + 1, vector<long>(n + 1, 0));
            dp[0][0] = 1;

            for (int i = 0; i <= goal; ++i) {
                for (int j = 1; j <= min(i, n); ++j) {
                    // The i-th song is a new song
                    dp[i][j] = dp[i - 1][j - 1] * (n - j + 1) % MOD;

                    // The i-th song is a song we have played before
                    if (j > k) {
                        dp[i][j] = (dp[i][j] + dp[i - 1][j] * (j - k)) % MOD;
                    }
                }
            }
            return dp[goal][n];
        }
    };
} // namespace
