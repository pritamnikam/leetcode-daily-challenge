/*
990. Satisfiability of Equality Equations
https://leetcode.com/problems/satisfiability-of-equality-equations/

You are given an array of strings equations that represent relationships between variables where each string equations[i] is of length 4 and takes one of two different forms: "xi==yi" or "xi!=yi".Here, xi and yi are lowercase letters (not necessarily different) that represent one-letter variable names.

Return true if it is possible to assign integers to variable names so as to satisfy all the given equations, or false otherwise.



Example 1:

Input: equations = ["a==b","b!=a"]
Output: false
Explanation: If we assign say, a = 1 and b = 1, then the first equation is satisfied, but not the second.
There is no way to assign the variables to satisfy both equations.
Example 2:

Input: equations = ["b==a","a==b"]
Output: true
Explanation: We could assign a = 1 and b = 1 to satisfy both equations.


Constraints:

1 <= equations.length <= 500
equations[i].length == 4
equations[i][0] is a lowercase letter.
equations[i][1] is either '=' or '!'.
equations[i][2] is '='.
equations[i][3] is a lowercase letter.


Intuition:
We have 26 nodes in the graph.
All "==" equations actually represent the connection in the graph.
The connected nodes should be in the same color/union/set.

Then we check all inequations.
Two inequal nodes should be in the different color/union/set.

Explanation
We can solve this problem by DFS or Union Find.

Firt pass all "==" equations.
Union equal letters together
Now we know which letters must equal to the others.

Second pass all "!=" inequations,
Check if there are any contradict happens.

Time Complexity:
Union Find Operation, amortized O(1)
First pass all equations, O(N)
Second pass all inequations, O(N)

Overall O(N)


*/

using namespace std;

#include <vector>
#include <string>

namespace {
    class Solution {
        int uf[26];
    public:
        bool equationsPossible(vector<string>& equations) {
            init();

            for (string e : equations)
                if (e[1] == '=')
                    // uf[find(e[0] - 'a')] = find(e[3] - 'a');
                    Union(e[0] - 'a', e[3] - 'a');

            for (string e : equations)
                if (e[1] == '!' && find(e[0] - 'a') == find(e[3] - 'a'))
                    return false;

            return true;
        }

    private:
        int find(int x) {
            if (x != uf[x]) uf[x] = find(uf[x]);
            return uf[x];
        }

        void init() {
            for (int i = 0; i < 26; ++i) uf[i] = i;
        }

        void Union(int x, int y) {
            uf[find(x)] = find(y);
        }
    };
}
