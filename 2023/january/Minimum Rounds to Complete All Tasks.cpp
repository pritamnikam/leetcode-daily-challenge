/*
2244. Minimum Rounds to Complete All Tasks
https://leetcode.com/problems/minimum-rounds-to-complete-all-tasks/

You are given a 0-indexed integer array tasks, where tasks[i] represents the difficulty level of a task. 
In each round, you can complete either 2 or 3 tasks of the same difficulty level.

Return the minimum rounds required to complete all the tasks, or -1 if it is not possible to complete all the tasks.



Example 1:
Input: tasks = [2,2,3,3,2,4,4,4,4,4]
Output: 4
Explanation: To complete all the tasks, a possible plan is:
- In the first round, you complete 3 tasks of difficulty level 2.
- In the second round, you complete 2 tasks of difficulty level 3.
- In the third round, you complete 3 tasks of difficulty level 4.
- In the fourth round, you complete 2 tasks of difficulty level 4.
It can be shown that all the tasks cannot be completed in fewer than 4 rounds, so the answer is 4.

Example 2:
Input: tasks = [2,3,3]
Output: -1
Explanation: There is only 1 task of difficulty level 2, but in each round, you can only complete either 2 or 3 tasks of the same difficulty level. Hence, you cannot complete all the tasks, and the answer is -1.


Constraints:
1 <= tasks.length <= 105
1 <= tasks[i] <= 109

*/

using namespace std;

#include <iostream>
#include <vector>
#include <unordered_map>

namespace {
    class Solution {
    public:
        int minimumRounds(vector<int>& tasks) {
            unordered_map<int, int> freq;
            // Store the frequencies in the map.
            for (int task : tasks) {
                freq[task]++;
            }

            int minimumRounds = 0;
            // Iterate over the task's frequencies.
            for (auto& it : freq) {
                int count = it.second;

                // If the frequency is 1, it's not possible to complete tasks.
                if (count == 1) {
                    return -1;
                }

                if (count % 3 == 0) {
                    // Group all the task in triplets.
                    minimumRounds += count / 3;
                }
                else {
                    // If count % 3 = 1; (count / 3 - 1) groups of triplets and 2 pairs.
                    // If count % 3 = 2; (count / 3) groups of triplets and 1 pair.
                    minimumRounds += count / 3 + 1;
                }
            }

            return minimumRounds;
        }
    };

} // namespace

void testMinimumRoundsToCompleteAllTasks() {
    // Input: tasks = [2,2,3,3,2,4,4,4,4,4], Output: 4
    vector<int> tasks = { 2, 2, 3, 3, 2, 4, 4, 4, 4, 4 };
    cout << "Minimum Rounds to Complete All Tasks: " << Solution().minimumRounds(tasks) << endl;

    // Input: tasks = [2,3,3], Output: -1
    tasks = { 2,3,3 };
    cout << "Minimum Rounds to Complete All Tasks: " << Solution().minimumRounds(tasks) << endl;
}
