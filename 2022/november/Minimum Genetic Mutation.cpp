/*
433. Minimum Genetic Mutation
https://leetcode.com/problems/minimum-genetic-mutation/

A gene string can be represented by an 8-character long string, with choices from 'A', 'C', 'G', and 'T'.

Suppose we need to investigate a mutation from a gene string start to a gene string end where one mutation
is defined as one single character changed in the gene string.

For example, "AACCGGTT" --> "AACCGGTA" is one mutation.
There is also a gene bank bank that records all the valid gene mutations. A gene must be in bank to make it
a valid gene string.

Given the two gene strings start and end and the gene bank bank, return the minimum number of mutations needed
to mutate from start to end. If there is no such a mutation, return -1.

Note that the starting point is assumed to be valid, so it might not be included in the bank.



Example 1:

Input: start = "AACCGGTT", end = "AACCGGTA", bank = ["AACCGGTA"]
Output: 1
Example 2:

Input: start = "AACCGGTT", end = "AAACGGTA", bank = ["AACCGGTA","AACCGCTA","AAACGGTA"]
Output: 2
Example 3:

Input: start = "AAAAACCC", end = "AACCCCCC", bank = ["AAAACCCC","AAACCCCC","AACCCCCC"]
Output: 3


Constraints:

start.length == 8
end.length == 8
0 <= bank.length <= 10
bank[i].length == 8
start, end, and bank[i] consist of only the characters ['A', 'C', 'G', 'T'].
*/


using namespace std;

#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include <queue>

namespace {

    class Solution {
    public:
        int minMutation(string start, string end, vector<string>& bank) {
            // BFS: Level-order-traversal
            unordered_set<string> seen, mutations(bank.begin(), bank.end());
            queue<string> queue; queue.push(start); seen.insert(start);

            int steps = 0;
            while (!queue.empty()) {
                int nodesInQueue = queue.size();

                for (int j = 0; j < nodesInQueue; ++j) {
                    string node = queue.front();
                    queue.pop();

                    if (node == end) {
                        return steps;
                    }

                    for (char ch : "ACTG") {
                        for (int i = 0; i < node.size(); i++) {
                            string neighbor = node;
                            neighbor[i] = ch;

                            if (!seen.count(neighbor)
                                && mutations.count(neighbor)) {
                                queue.push(neighbor);
                                seen.insert(neighbor);
                            }
                        }
                    }                    
                }
                ++steps;
            }
            return steps;
        }
    };

} // namespace

void testMinimumGeneticMutation() {
    // start = "AAAAACCC", end = "AACCCCCC", bank = ["AAAACCCC","AAACCCCC","AACCCCCC"]
    string start = "AAAAACCC", end = "AACCCCCC";
    vector<string> bank = { "AAAACCCC", "AAACCCCC", "AACCCCCC" };

    cout << "Minimum Genetic Mutation: " << Solution().minMutation(start, end, bank) << endl;
}
