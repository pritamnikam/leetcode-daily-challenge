// 1792. maximum-average-pass-ratio
// https://leetcode.com/problems/maximum-average-pass-ratio/

class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        // Lambda to calculate the gain of adding an extra student
        auto calculateGain = [](int passes, int totalStudents) {
            return (double)(passes + 1) / (totalStudents + 1) -
                   (double)passes / totalStudents;
        };

        // max heap to store {-gai, passes, totalstudent}
        priority_queue<pair<double, pair<int, int>>> pq;
        for (const auto& i: classes) {
            pq.push(
                {
                    calculateGain(i[0], i[1]),
                    {i[0], i[1]}
                }
            );
        }

        while (extraStudents--) {
            auto [currentGain, classInfo] = pq.top();
            pq.pop();
            int passes = classInfo.first;
            int totalStudents = classInfo.second;
            pq.push({calculateGain(passes + 1, totalStudents + 1),
                          {passes + 1, totalStudents + 1}});
        }

        // Calculate the final average pass ratio
        double totalPassRatio = 0;
        while (!pq.empty()) {
            auto [_, classInfo] = pq.top();
            pq.pop();
            totalPassRatio += (double)classInfo.first / classInfo.second;
        }

        return totalPassRatio / classes.size();
    }
};
