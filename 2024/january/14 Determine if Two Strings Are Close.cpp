// 1657. Determine if Two Strings Are Close
// https://leetcode.com/problems/determine-if-two-strings-are-close/description/

class Solution {
public:
    bool closeStrings(string word1, string word2) {
        set<char> s1, s2;
        vector<int> m1(26, 0), m2(26, 0);

        for (char ch: word1) {
            s1.insert(ch);
            m1[ch - 'a']++;
        }

        for (char ch: word2) {
            s2.insert(ch);
            m2[ch - 'a']++;
        }

        sort(m1.begin(), m1.end());
        sort(m2.begin(), m2.end());

        return s1 == s2 && m1 == m2;
    }
};
