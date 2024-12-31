// 983. minimum-cost-for-tickets
// https://leetcode.com/problems/minimum-cost-for-tickets

// dp(i)=min(dp(i+1)+costs[0],
//           dp(i+7)+costs[1],
//           dp(i+30)+costs[2])


class Solution {
    vector<int> costs;
    vector<int> memo;
    unordered_set<int> dayset;
    
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        this->costs = costs;
        memo = vector<int>(366);
        for (int d: days) dayset.insert(d);
        return dp(1);
    }
    
    int dp(int i) {
        if (i > 365)
            return 0;
        if (memo[i] != 0)
            return memo[i];
        
        int ans;
        if (dayset.count(i)) {
            ans = min(dp(i+1) + costs[0], dp(i+7) + costs[1]);
            ans = min(ans, dp(i+30) + costs[2]);
        } else {
            ans = dp(i+1);
        }
        
        memo[i] = ans;
        return ans;
    }
};
