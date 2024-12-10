// 2981. find-longest-special-substring-that-occurs-thrice-i
// https://leetcode.com/problems/find-longest-special-substring-that-occurs-thrice-i

class Solution {
public:
    int maximumLength(string s) {
        map<pair<char, int>, int> count;
        int substringLength = 0;

        for (int i = 0; i < s.length(); i++) {
            char ch = s[i];
            substringLength = 0;

            for (int j = i; j < s.length(); j++) {
                if (ch == s[j]) {
                    substringLength++;
                    count[{ch, substringLength}]++;
                } else {
                    break;
                }
            }
        }

        int ans = 0;
        for (auto i: count) {
            int n = i.first.second;
            if (i.second >= 3 && n > ans) {
                ans = n;
            }
        }

        return ans == 0 ? -1 : ans;
    }
};
