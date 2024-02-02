// 1291. Sequential Digits
// https://leetcode.com/problems/sequential-digits
class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> answer;

        for (int i = 1; i <= 9; i++) {
            dfs(
                low,
                high,
                i,
                0,
                answer
            );
        }

        sort(answer.begin(), answer.end());
        return answer;
    }

    private:
    void dfs(
        int low,
        int high,
        int i,
        int num,
        vector<int>& answer
    ) {
        if (num >= low && num <= high) {
            answer.push_back(num);
        }

        if (num > high || i > 9) {
            return;
        }

        dfs(
            low,
            high,
            i + 1,
            num * 10 + i,
            answer
        );
    }
};
