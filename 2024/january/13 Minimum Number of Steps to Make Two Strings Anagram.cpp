// 1347. Minimum Number of Steps to Make Two Strings Anagram
// https://leetcode.com/problems/minimum-number-of-steps-to-make-two-strings-anagram/

class Solution {
public:
    int minSteps(string s, string t) {
        unordered_map<char, int> count;
        for (char ch: s) {
            count[ch]++;
        }

        for (char ch: t) {
            if (count.count(ch) && count[ch]) {
                count[ch]--;
            }
        }

        int n = 0;
        for (auto [key, val]: count) {
            n += val;
        }

        return n;
    }
};
