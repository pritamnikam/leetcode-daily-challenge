// 514. Freedom Trial
// https://leetcode.com/problems/freedom-trail/


class Solution {
public:
    int findRotateSteps(string ring, string key) {
        unordered_map<int, unordered_map<int, int>> bestSteps;
        return tryLock(
            0,
            0,
            ring,
            key,
            INT_MAX,
            bestSteps
        );
    }

private:
    // Find the minimum steps between two indexes of ring
    int countSteps(int curr, int next, int ringLength) {
        int stepsBetween = abs(curr - next);
        int stepsAround = ringLength - stepsBetween;
        return min(stepsBetween, stepsAround);
    }

    // Find the minimum number of steps to spell the keyword
    int tryLock(
      int ringIndex, 
      int keyIndex, 
      string ring,
      string key,
      int minSteps,
      unordered_map<int, unordered_map<int, int>>& bestSteps
    ) {
        // If we have already calculated this sub-problem, return the result
        if (bestSteps[ringIndex][keyIndex]) {
            return bestSteps[ringIndex][keyIndex];
        }

        // If we reach the end of the key, it has been spelled
        if (keyIndex == key.length()) {
            return 0;
        }
        // For each occurrence of the character at index key_index of key in ring
        // Calculate the minimum steps to that character from the ringIndex of ring
        for (int i = 0; i < ring.length(); i++) {
            if (ring[i] == key[keyIndex]) {
                int totalSteps = countSteps(
                    ringIndex,
                    i, 
                    ring.length()) + 1 + tryLock(i, keyIndex + 1, ring, key, INT_MAX, bestSteps);
                minSteps = min(minSteps, totalSteps);
                bestSteps[ringIndex][keyIndex] = minSteps;
            }
        }
        return minSteps;
    }

};
