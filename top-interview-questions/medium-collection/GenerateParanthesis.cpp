/*
Generate Parentheses

Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

Example 1:

Input: n = 3
Output: ["((()))","(()())","(())()","()(())","()()()"]
Example 2:

Input: n = 1
Output: ["()"]


Constraints:
1 <= n <= 8

*/

using namespace std;

#include <vector>
#include <string>
#include <queue>

struct Parenthesis {
    int openCount;
    int closeCount;
    string str;

    Parenthesis() : openCount(0), closeCount(0), str("") {}
    Parenthesis(int i, int j, string s) : openCount(i), closeCount(j), str(s) {}
};

class Solution {

public:
    // BFS:
    vector<string> generateParenthesis(int n) {
        vector<string> result;

        queue<Parenthesis> queue;
        queue.push({ 0, 0, "" });

        while (!queue.empty()) {
            Parenthesis p = queue.front();
            queue.pop();

            // base case:
            if (p.openCount == n && p.closeCount == n) {
                result.push_back(p.str);
            }
            else {
                if (p.openCount < n) {
                    queue.push({
                        1 + p.openCount,
                        p.closeCount,
                        p.str + '('
                        });
                }
                
                if (p.closeCount < p.openCount) {
                    queue.push({
                        p.openCount,
                        1 + p.closeCount,
                        p.str + ')'
                        });
                }
            }
        }

        return result;
    }
};