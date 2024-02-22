// 997. Find the Town Judge
// https://leetcode.com/problems/find-the-town-judge/

class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        if (trust.size() == 0 && n == 1) {
            return 1;
        }

        vector<int> count(n + 1);
        for (auto& t: trust) {
            count[t[0]]--;
            count[t[1]]++;
        }

        for (int u = 0; u < count.size(); ++u) {
            if (count[u] == n - 1) return u;
        }
        return -1;
    }
};
