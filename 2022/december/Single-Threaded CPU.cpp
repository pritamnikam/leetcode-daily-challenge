/*
1834. Single-Threaded CPU
https://leetcode.com/problems/single-threaded-cpu/

You are given n tasks labeled from 0 to n - 1 represented by a 2D integer array tasks, 
where tasks[i] = [enqueueTimei, processingTimei] means that the ith task will be available to process at 
enqueueTimei and will take processingTimei to finish processing.

You have a single-threaded CPU that can process at most one task at a time and will act in the following way:

If the CPU is idle and there are no available tasks to process, the CPU remains idle.
If the CPU is idle and there are available tasks, the CPU will choose the one with the shortest processing time. 
If multiple tasks have the same shortest processing time, it will choose the task with the smallest index.
Once a task is started, the CPU will process the entire task without stopping.
The CPU can finish a task then start a new one instantly.
Return the order in which the CPU will process the tasks.



Example 1:

Input: tasks = [[1,2],[2,4],[3,2],[4,1]]
Output: [0,2,3,1]
Explanation: The events go as follows:
- At time = 1, task 0 is available to process. Available tasks = {0}.
- Also at time = 1, the idle CPU starts processing task 0. Available tasks = {}.
- At time = 2, task 1 is available to process. Available tasks = {1}.
- At time = 3, task 2 is available to process. Available tasks = {1, 2}.
- Also at time = 3, the CPU finishes task 0 and starts processing task 2 as it is the shortest. Available tasks = {1}.
- At time = 4, task 3 is available to process. Available tasks = {1, 3}.
- At time = 5, the CPU finishes task 2 and starts processing task 3 as it is the shortest. Available tasks = {1}.
- At time = 6, the CPU finishes task 3 and starts processing task 1. Available tasks = {}.
- At time = 10, the CPU finishes task 1 and becomes idle.
Example 2:

Input: tasks = [[7,10],[7,12],[7,5],[7,4],[7,2]]
Output: [4,3,2,0,1]
Explanation: The events go as follows:
- At time = 7, all the tasks become available. Available tasks = {0,1,2,3,4}.
- Also at time = 7, the idle CPU starts processing task 4. Available tasks = {0,1,2,3}.
- At time = 9, the CPU finishes task 4 and starts processing task 3. Available tasks = {0,1,2}.
- At time = 13, the CPU finishes task 3 and starts processing task 2. Available tasks = {0,1}.
- At time = 18, the CPU finishes task 2 and starts processing task 0. Available tasks = {1}.
- At time = 28, the CPU finishes task 0 and starts processing task 1. Available tasks = {}.
- At time = 40, the CPU finishes task 1 and becomes idle.


Constraints:

tasks.length == n
1 <= n <= 105
1 <= enqueueTimei, processingTimei <= 109

*/
using namespace std;

#include <iostream>
#include <vector>
#include <queue>


/*
The problem statement asks us to create a scheduling policy that prioritizes the shortest available task;
this is known as Shortest Job First (SJF) CPU Scheduling. In SJF CPU Scheduling:

- If the CPU is idle and there are available tasks, the CPU will choose the one with the shortest processing time. 
  If multiple tasks have the same shortest processing time, it will choose the task with the smallest index 
  (the task which arrived first).

- Once the CPU starts to execute a task, it will process the entire task without stopping, i.e. it is non-preemptive.
*/

namespace {
    

    class Solution {
    public:
        vector<int> getOrder(vector<vector<int>>& tasks) {
            // Sort based on min task processing time or min task index.
            priority_queue<
                pair<int, int>, 
                vector<pair<int, int>>, 
                greater<>> nextTask;

            // Store task {enqueue time, processing time, index}.
            vector<vector<int>> sortedTasks;
            for (int i = 0; i < tasks.size(); ++i) {
                sortedTasks.push_back({ tasks[i][0], tasks[i][1], i });
            }
            sort(sortedTasks.begin(), sortedTasks.end());


            vector<int> tasksProcessingOrder;
            long long currTime = 0;
            int taskIndex = 0;

            // Stop when no tasks are left in array and heap.
            while (taskIndex < tasks.size() || !nextTask.empty()) {
                if (nextTask.empty() && currTime < sortedTasks[taskIndex][0]) {
                    // When the heap is empty, try updating currTime to next
                    // task's enqueue time.
                    currTime = sortedTasks[taskIndex][0];
                }

                // Push all the tasks whose enqueueTime <= currtTime into the heap.
                while (taskIndex < sortedTasks.size() && currTime >= sortedTasks[taskIndex][0]) {
                    nextTask.push({ sortedTasks[taskIndex][1], sortedTasks[taskIndex][2] });
                    ++taskIndex;
                }

                auto& t = nextTask.top();
                int processTime = t.first,
                    index = t.second;
                nextTask.pop();

                // Complete this task and increment currTime.
                currTime += processTime;
                tasksProcessingOrder.emplace_back(index);
            }

            return tasksProcessingOrder;
        }
    };
} // namespace

void testSingleThreadedCPU() {
    // Input: tasks = [[1,2],[2,4],[3,2],[4,1]], Output: [0, 2, 3, 1]

    vector<vector<int>> tasks = { {1, 2},{2, 4},{3, 2},{4, 1} };
    vector<int> output = Solution().getOrder(tasks);
}
