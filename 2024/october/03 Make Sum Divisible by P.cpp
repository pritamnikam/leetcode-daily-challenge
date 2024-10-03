// 1590. Make Sum Divisible by P
// https://leetcode.com/problems/make-sum-divisible-by-p

class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int n = nums.size();
        int totalSum = 0;

        // Step 1: calculate total sum and target reminder
        for (int num: nums) {
            totalSum = (totalSum + num) % p;
        }

        int target = totalSum % p;
        // The array is already divisible by p
        if (target == 0) return 0;

        // Step 2: use hashmap to track prefix sum mod p
        unordered_map<int, int> modMap;
        
        // to handle case where the whole prefix is the answer
        modMap[0] = -1;

        int currentSum = 0, minLen = n;

        // Step 3: iterate over array
        for (int i = 0; i < n; i++) {
            currentSum = (currentSum + nums[i]) % p;

            // calculate what we need to remove
            int needed = (currentSum - target + p) % p;

            // if we have seen the needed remainder, we can consider this subarray
            if (modMap.count(needed)) {
                minLen = min(minLen, i - modMap[needed]);
            }

            // store the current reminder and index
            modMap[currentSum] = i;
        }

        // step 4: return result
        return minLen == n ? -1 : minLen;

    }
};
