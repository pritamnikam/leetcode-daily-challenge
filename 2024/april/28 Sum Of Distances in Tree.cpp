// 834. Sum Of Distances in Tree
// https://leetcode.com/problems/sum-of-distances-in-tree

class Solution {
    vector<unordered_set<int>> tree;
    vector<int> count;
    vector<int> res;
public:
    vector<int> sumOfDistancesInTree(int N, vector<vector<int>>& edges) {
        tree.resize(N);
        res.assign(N, 0);
        count.assign(N, 1);

        for (auto& edge: edges) {
            tree[edge[0]].insert(edge[1]);
            tree[edge[1]].insert(edge[0]);
        }

        dfs(0, -1);
        dfs2(0, -1);
        return res;
    }

private:
    void dfs(int root, int pre) {
        for (auto i : tree[root]) {
            if (i == pre) continue;
            dfs(i, root);
            count[root] += count[i];
            res[root] += res[i] + count[i];
        }
    }

    void dfs2(int root, int pre) {
        for (auto i : tree[root]) {
            if (i == pre) continue;
            res[i] = res[root]
                - count[i]
                + count.size()
                - count[i];
            dfs2(i, root);
        }
    }
};
