// 1422. Maximum Score After Splitting a String
// https://leetcode.com/problems/maximum-score-after-splitting-a-string/

class Solution {
public:
    int maxScore(string s) {
        int ones = count(s.begin(), s.end(), '1');
        int ans = 0, zeros = 0;
        for (int i = 0; i < s.size() - 1; i++) {
            if (s[i] == '1') ones--;
            else zeros++;
            ans = max(ans, zeros + ones);
        }
        return ans;
    }
};
