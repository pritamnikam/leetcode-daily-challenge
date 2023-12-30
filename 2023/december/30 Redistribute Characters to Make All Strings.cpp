// 1897. Redistribute Characters to Make All Strings
// https://leetcode.com/problems/redistribute-characters-to-make-all-strings-equal

class Solution {
public:
    bool makeEqual(vector<string>& words) {
        vector<int> count(26, 0);
        for (string& word: words) {
            for (char ch: word) {
                count[ch - 'a']++;
            }
        }

        int n = words.size();
        for (int val: count) {
            if (val % n != 0)
                return false;
        }

        return true;
    }
};
