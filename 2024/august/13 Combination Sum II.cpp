// 40. Combination Sum II
// https://leetcode.com/problems/combination-sum-ii


class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        // 1. Sort inputs
        sort(candidates.begin(), candidates.end());

        // 2. Backtrack:
        vector<vector<int>> result;
        vector<int> cur;
        Backtrack(candidates, target, 0, cur, result);

        return result;
    }
private:
    void Backtrack(vector<int>& input, 
                   int target,
                   int index, 
                   vector<int>& cur, 
                   vector<vector<int>>& result) {
		if (target == 0) {
			result.push_back(cur);
			return;
		}

		for (int nextIndex = index; nextIndex < input.size(); ++nextIndex) {
            if (nextIndex > index && 
                input[nextIndex] == input[nextIndex - 1]) {
                continue;
            }
        

            int pick = input[nextIndex];

            // optimization: early stopping
            if (target - pick < 0)
                break;

            cur.push_back(pick);
            Backtrack(input, target - pick, nextIndex + 1, cur, result);
            cur.pop_back();
        }
	}
};
