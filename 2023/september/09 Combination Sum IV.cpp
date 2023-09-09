class Solution {
public:
    unordered_map<int, int> cache;
    int combinationSum4(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        return combinationSumMemo(nums, target);
        // return combinationSumDP(nums, target);
    }
    
    int combinationSumMemo(vector<int>& nums, int remaining) {
        // reached the target
        if (remaining == 0) return 1;
        
        // we already know the answer
        if (cache.count(remaining)) return cache[remaining];
        
        int result = 0;
        
        // for every number try calculating the sum
        for (int num: nums) {
            if (remaining >= num) {
                result += combinationSumMemo(nums, remaining - num);
            } else {
                break;
            }
        }
        
        cache[remaining] = result;
        return result;
    }
    
    int combinationSumDP(vector<int>& nums, int target) {
        vector<long long> dp(target + 1);
        dp[0] = 1;
        
        // bottum-up for all sum
        for (int sum = 1; sum <= target; ++sum) {
            // for every number try calculating the sum
            for (int num: nums) {
                if (sum - num >= 0) {
                    dp[sum] += dp[sum - num];
                } else {
                    break;
                }
            }
        }
        
        return dp[target];
    }
};
