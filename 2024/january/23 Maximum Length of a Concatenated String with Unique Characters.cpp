// 1239. Maximum Length of a Concatenated String with Unique Characters 
// https://leetcode.com/problems/maximum-length-of-a-concatenated-string-with-unique-characters

class Solution {
public:
    int maxLength(vector<string>& arr) {
        return dfs(
            arr,
            0,
            ""
        );
    }

    private:
    int dfs(
        vector<string>& arr,
        int pos,
        string result
    ) {
        /// duplication of char
        unordered_set<char> resultSet(result.begin(), result.end());
        if (result.size() != resultSet.size()) {
            return 0;
        }

        int best = result.size();
        for (int i = pos; i < arr.size(); i++) {
            best = max(
                best,
                dfs(
                    arr,
                    i + 1,
                    result + arr[i]
                )
            );
        }

        return best;
    }
};
