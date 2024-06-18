// 826. Most Profit Assigning Work
// https://leetcode.com/problems/most-profit-assigning-work


class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        vector<pair<int, int>> jobProfile;
        jobProfile.push_back({0,0});

        int n = difficulty.size();

        for (int i = 0; i < n; i++) {
            jobProfile.push_back({
                difficulty[i], profit[i]
            });
        }

        // sort by difficulty
        sort(jobProfile.begin(), jobProfile.end());

        for (int i = 0; i < n; i++) {
            jobProfile[i + 1].second = max(
                jobProfile[i].second,
                jobProfile[i + 1].second
            );
        }

        int netProfit = 0;

        for (int  i = 0; i < worker.size(); i++) {
            int ability = worker[i];

            // find the job with just smaller or equal difficulty that ability
            int l = 0, r = n, jobProfit = 0;
            while (l <= r) {
                int mid = (l + r) / 2;
                if (jobProfile[mid].first <= ability) {
                    jobProfit = max(jobProfit, jobProfile[mid].second);
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }

            // Increment profit of current worker to total profit.
            netProfit += jobProfit;
        }

        return netProfit;
    }
};
