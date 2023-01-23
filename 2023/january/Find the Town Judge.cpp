/*
997. Find the Town Judge
https://leetcode.com/problems/find-the-town-judge/

In a town, there are n people labeled from 1 to n. There is a rumor that one of these people
is secretly the town judge.

If the town judge exists, then:
- The town judge trusts nobody.
- Everybody (except for the town judge) trusts the town judge.
- There is exactly one person that satisfies properties 1 and 2.

You are given an array trust where trust[i] = [ai, bi] representing that the person 
labeled ai trusts the person labeled bi.

Return the label of the town judge if the town judge exists and can be identified, 
or return -1 otherwise.

Example 1:
Input: n = 2, trust = [[1,2]]
Output: 2

Example 2:
Input: n = 3, trust = [[1,3],[2,3]]
Output: 3

Example 3:
Input: n = 3, trust = [[1,3],[2,3],[3,1]]
Output: -1


Constraints:
1 <= n <= 1000
0 <= trust.length <= 104
trust[i].length == 2
All the pairs of trust are unique.
ai != bi
1 <= ai, bi <= n

*/

using namespace std;

#include <vector>
#include <iostream>

namespace {
    class Solution {
    public:
        int findJudge(int n, vector<vector<int>>& trust) {
            if (trust.size() == 0 && n == 1)
                return 1;

            vector<int> count(n + 1);
            for (auto& person : trust) {
                // decrements the trust count of the first person in the pair.
                // This is done because if the first person trusts the second person, 
                // it means that the first person does not trust themselves.
                count[person[0]]--;

                // increments the trust count of the second person in the pair.
                // This is done because if the first person trusts the second person,
                // it means that the second person is trusted by the first person.
                count[person[1]]++;
            }

            for (int person = 0; person < count.size(); person++) {
                // check if there is a person who is trusted by everyone except themselves
                // (n-1 people) and if such person exists it returns the index of that person.
                if (count[person] == n - 1) return person;
            }
            return -1;
        }
    };
}  // namespace

void testFindTheTownJudge() {
    /*
        Example 1:
        Input: n = 2, trust = [[1,2]]
        Output: 2

        Example 2:
        Input: n = 3, trust = [[1,3],[2,3]]
        Output: 3

        Example 3:
        Input: n = 3, trust = [[1,3],[2,3],[3,1]]
        Output: -1
    */
    int n = 3;
    vector<vector<int>> trust = { {1, 3},{2, 3},{3, 1 } };
    cout << "Find the Town Judge: " << Solution().findJudge(n, trust) << endl;

    n = 3;
    trust = { {1, 3}, {2, 3} };
    cout << "Find the Town Judge: " << Solution().findJudge(n, trust) << endl;
}
