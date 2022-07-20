/*
621. Task Scheduler
https://leetcode.com/problems/task-scheduler/

Given a characters array tasks, representing the tasks a CPU needs to do, 
where each letter represents a different task. 

Tasks could be done in any order. Each task is done in one unit of time. 
For each unit of time, the CPU could complete either one task or just be idle.

However, there is a non-negative integer n that represents the cooldown period 
between two same tasks (the same letter in the array), that is that there must 
be at least n units of time between any two same tasks.

Return the least number of units of times that the CPU will take to finish all the given tasks.

Example 1:
Input: tasks = ["A","A","A","B","B","B"], n = 2
Output: 8
Explanation:
A -> B -> idle -> A -> B -> idle -> A -> B
There is at least 2 units of time between any two same tasks.

Example 2:
Input: tasks = ["A","A","A","B","B","B"], n = 0
Output: 6
Explanation: On this case any permutation of size 6 would work since n = 0.
["A","A","A","B","B","B"]
["A","B","A","B","A","B"]
["B","B","B","A","A","A"]
...
And so on.

Example 3:
Input: tasks = ["A","A","A","A","A","A","B","C","D","E","F","G"], n = 2
Output: 16
Explanation:
One possible solution is
A -> B -> C -> A -> D -> E -> A -> F -> G -> A -> idle -> idle -> A -> idle -> idle -> A

Constraints:
1 <= task.length <= 104
tasks[i] is upper-case English letter.
The integer n is in the range [0, 100].

*/

using namespace std;

#include <iostream>

#include <vector>
#include <queue>
#include <unordered_map>

namespace {
	struct Compare {
		bool operator()(const pair<int, int>& x, const pair<int, int>& y) {
			return y.second > x.second;
		}
	};

	class Solution {
	public:
		int leastInterval(vector<char>& tasks, int k) {
			unordered_map<char, int> taskFrequencyMap;
			for (char chr : tasks) {
				taskFrequencyMap[chr]++;
			}

			priority_queue< pair<char, int>,
							vector<pair<char, int>>,
							Compare> maxHeap;

			// add all tasks with frequencies to max-heap
			for (auto& it : taskFrequencyMap) {
				maxHeap.push({ it.first, it.second });
			}

			int intervalCount = 0;
			while (!maxHeap.empty()) {
				queue<pair<char, int>> waitList;

				// try to execute as many as 'k+1' tasks from the max-heap
				int n = k + 1;
				for (; n > 0 && !maxHeap.empty(); --n) {
					intervalCount++;
					pair<int, int> top = maxHeap.top();
					maxHeap.pop();

					if (top.second > 1) {
						top.second--;
						waitList.push({ top.first, top.second });
					}
				}
				
				// put all the waiting list back on the heap
				while (!waitList.empty()) {
					maxHeap.push(waitList.front());
					waitList.pop();
				}

				// we'll be having 'n' idle intervals for the next iteration
				if (!maxHeap.empty()) {
					intervalCount += n;
				}
			}

			return intervalCount;
		}

		int leastIntervalMath(vector<char>& tasks, int k) {
			unordered_map<char, int> taskFrequencyMap;
			int f_max = 0, n_max = 0;
			for (char chr : tasks) {
				taskFrequencyMap[chr]++;

				// max frequency
				f_max = max(f_max, taskFrequencyMap[chr]);
			}

			// count the most frequent tasks
			for (auto& it : taskFrequencyMap) {
				if (it.second == f_max)
					++n_max;
			}

			return max((int)tasks.size(), ((f_max - 1) * (k + 1) + n_max));
		}
	};
}

void testTaskScheduler() {
	vector<char> tasks = { 'A', 'A', 'A', 'B', 'B', 'B'};
	int n = 2;

	cout << "Task Scheduler: " << Solution().leastInterval(tasks, n) << endl;
}
