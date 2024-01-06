// 1235. Maximum Profit in Job Scheduling
// https://leetcode.com/problems/maximum-profit-in-job-scheduling

class Solution {
public:
    int jobScheduling(
        vector<int>& startTime, 
        vector<int>& endTime, 
        vector<int>& profits) {
        
        // sort jobs by end time
        int n = startTime.size();
        vector<vector<int>> jobs;
        for (int i = 0; i < n; ++i) {
            jobs.push_back({ 
                endTime[i], // end
                startTime[i], // start
                profits[i]  // profit
                });
        }
        sort(jobs.begin(), jobs.end());

        // binary search for each job
        map<int, int> dp = {{0, 0}};
        for (auto& job : jobs) {
            int start = job[1],
                end = job[0],
                profit = job[2];

            int cur = prev(dp.upper_bound(start))->second + profit;
            if (cur > dp.rbegin()->second)
                dp[end] = cur;
        }

        return dp.rbegin()->second;        
    }
};
