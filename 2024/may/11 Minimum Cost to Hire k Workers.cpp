// 857. Minimum Cost to Hire k Workers
// https://leetcode.com/problems/minimum-cost-to-hire-k-workers/

class Solution {
    public:
        double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
            int totalWorkers = quality.size();
            double totalCost = numeric_limits<double>::max();
            double currentTotalQuality = 0;
            
            // 1. Store wage-to-quality ratio along with quality
            vector<pair<double, int>> wageToQualityRatio;

            // 2. Calculate wage-to-quality ratio for each worker
            for (int i = 0; i < totalWorkers; i++) {
                wageToQualityRatio.push_back({ static_cast<double>(wage[i]) / quality[i], quality[i] });
            }

            // 3. sort workers based on their wage-to-quality ratio
            sort(
                wageToQualityRatio.begin(),
                wageToQualityRatio.end()
            );

            // 4. Use max heap to keep track of highest quality workers
            priority_queue<int> highestQualityWorkers;

            for (int i = 0; i < totalWorkers; i++) {
                highestQualityWorkers.push(wageToQualityRatio[i].second);
                currentTotalQuality += wageToQualityRatio[i].second;

                // 5. if we have more than k workers
                // remove the one with highest quality
                if (highestQualityWorkers.size() > k) {
                    currentTotalQuality -= highestQualityWorkers.top();
                    highestQualityWorkers.pop();
                }

                // 6. if we have more than k workers
                // calculate the total cost and update if it's the minimum
                if (highestQualityWorkers.size() == k) {
                    totalCost = min(
                        totalCost,
                        currentTotalQuality * wageToQualityRatio[i].first
                    );
                }
            }

            return totalCost;
        }
};
