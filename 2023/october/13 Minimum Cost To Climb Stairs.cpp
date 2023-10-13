// 746. Minimum Cost To Climb Stairs
// https://leetcode.com/problems/min-cost-climbing-stairs

using namespace std;

#include <iostream>
#include <vector>
#include <unordered_map>

namespace {

class Solution {
public:
    unordered_map<int, int> cache;
    int minCostClimbingStairsMemo(vector<int>& cost) {
        return minCostClimbingStairs(cost, cost.size());
    }
    
    int minCostClimbingStairs(vector<int>& cost, int currentIndex) {
        if (cache.count(currentIndex)) {
            return cache[currentIndex];
        }
        
        if (currentIndex == 0 || currentIndex == 1) {
            return cache[currentIndex] = 0;
        }
        
        cache[currentIndex] = min(cost[currentIndex-1] + minCostClimbingStairs(cost,currentIndex-1),
                                  cost[currentIndex-2] + minCostClimbingStairs(cost,currentIndex-2));
        return cache[currentIndex];
    }
    
    int minCostClimbingStairs2(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n + 1);
        
        dp[0] = dp[1] = 0;
        for (int i = 2; i<=n;++i) {
            dp[i] = min(dp[i-1]+cost[i-1], 
                        dp[i-2]+cost[i-2]);
        }
        
        return dp[n];
    }
    
    int minCostClimbingStairs(vector<int>& cost) {
        int downOne = 0, downTwo = 0;
        for (int i = 2; i <= cost.size(); ++i) {
            int temp = downOne;
            downOne = min(downOne + cost[i-1], downTwo + cost[i-2]);
            downTwo = temp;
        }
        
        return downOne;
    }
};

} // nmesapce
