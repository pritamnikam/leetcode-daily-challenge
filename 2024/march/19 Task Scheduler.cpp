// 621. Task Scheduler
// https://leetcode.com/problems/task-scheduler/

class Solution {    
public:
    int leastInterval(vector<char> &tasks, int k) {
        int freq[26] = { 0 };
        int maxCount = 0;

        for (char ch: tasks) {
            freq[ch - 'A']++;
            maxCount = max(maxCount, freq[ch - 'A']);
        }

        size_t time = (maxCount - 1) * (k + 1);
        for (int f: freq) {
            if (f == maxCount) {
                time++;
            }
        }

        return max(time, tasks.size());
    }
};
