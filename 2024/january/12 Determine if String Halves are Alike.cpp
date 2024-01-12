// 1704. Determine if String Halves are Alike
// https://leetcode.com/problems/determine-if-string-halves-are-alike/

class Solution {
public:
    bool halvesAreAlike(string s) {
        int n = s.size();

        int count = 0;
        for (int i = 0 ; i < n/2; i++) {
            if (isVowels(s[i]))
                ++count;
        }

        for (int i = n/2; i < n; i++) {
            if (isVowels(s[i]))
                --count;
        }

        return count == 0;
    }

    private:
    unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
    bool isVowels(char ch) {
        return vowels.count(ch) != 0;
    }
};
