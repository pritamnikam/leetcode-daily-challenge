/*
838. Push Dominoes
https://leetcode.com/problems/push-dominoes/

There are n dominoes in a line, and we place each domino vertically upright. 
In the beginning, we simultaneously push some of the dominoes either to the
left or to the right.

After each second, each domino that is falling to the left pushes the adjacent
domino on the left. Similarly, the dominoes falling to the right push their 
adjacent dominoes standing on the right.

When a vertical domino has dominoes falling on it from both sides, it stays 
still due to the balance of the forces.

For the purposes of this question, we will consider that a falling domino 
expends no additional force to a falling or already fallen domino.

You are given a string dominoes representing the initial state where:

dominoes[i] = 'L', if the ith domino has been pushed to the left,
dominoes[i] = 'R', if the ith domino has been pushed to the right, and
dominoes[i] = '.', if the ith domino has not been pushed.
Return a string representing the final state.



Example 1:

Input: dominoes = "RR.L"
Output: "RR.L"
Explanation: The first domino expends no additional force on the second domino.
Example 2:


Input: dominoes = ".L.R...LR..L.."
Output: "LL.RR.LLRRLL.."


Constraints:

n == dominoes.length
1 <= n <= 105
dominoes[i] is either 'L', 'R', or '.'.

*/

using namespace std;

#include <iostream>
#include <string>
#include <vector>

namespace {
	class Solution {
	public:
		string pushDominoes(string dominoes) {
			int N = dominoes.size();
			vector<int> forces(N, 0);

			// left-to-right: Populate forces going from left to right
			int force = 0;
			for (int i = 0; i < N; ++i) {
				if (dominoes[i] == 'R') force = N;
				else if (dominoes[i] == 'L') force = 0;
				else force = max(force - 1, 0);

				forces[i] += force;
			}

			// right-to-left: Populate forces going from right to left
			force = 0;
			for (int i = N - 1; i >= 0; --i) {
				if (dominoes[i] == 'L') force = N;
				else if (dominoes[i] == 'R') force = 0;
				else force = max(force - 1, 0);

				forces[i] -= force;
			}

			string ans;
			for (int f : forces) {
				ans += (f > 0)
					? 'R'
					: ((f < 0)
						? 'L'
						: '.');
			}

			return ans;
		}

		// 2-pointers
		string pushDominoes2(string d) {
			d = 'L' + d + 'R';
			string res = "";
			for (int i = 0, j = 1; j < d.length(); ++j) {
				if (d[j] == '.') continue;
				int middle = j - i - 1;
				if (i > 0)
					res += d[i];
				if (d[i] == d[j])
					res += string(middle, d[i]);
				else if (d[i] == 'L' && d[j] == 'R')
					res += string(middle, '.');
				else
					res += string(middle / 2, 'R') 
							+ string(middle % 2, '.') 
							+ string(middle / 2, 'L');
				i = j;
			}
			return res;
		}
	};
}  // namespace
