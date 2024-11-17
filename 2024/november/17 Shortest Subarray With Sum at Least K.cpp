// 862. Shortest Subarray With Sum at Least K
// https://leetcode.com/problems/shortest-subarray-with-sum-at-least-k/

class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size();

        // build prefix array
        vector<long long> prefixSums(n + 1, 0);
        for (int i = 1; i <=n; i++) {
            prefixSums[i] = prefixSums[i - 1] + nums[i - 1];
        }

        deque<int> candidateIndices;
        int shortestSubarrayLength = INT_MAX;
        for (int i = 0; i <= n; i++) {
            // Remove candidates from front of deque where subarray sum meets
            // target
            while (!candidateIndices.empty() &&
                   prefixSums[i] - prefixSums[candidateIndices.front()] >=
                       k) {
                // Update shortest subarray length
                shortestSubarrayLength =
                    min(shortestSubarrayLength, i - candidateIndices.front());
                candidateIndices.pop_front();
            }

            // Maintain monotonicity by removing indices with larger prefix sums
            while (!candidateIndices.empty() &&
                   prefixSums[i] <= prefixSums[candidateIndices.back()]) {
                candidateIndices.pop_back();
            }

            // Add current index to candidates
            candidateIndices.push_back(i);
        }

        return shortestSubarrayLength == INT_MAX ? -1 : shortestSubarrayLength;
    }
};
