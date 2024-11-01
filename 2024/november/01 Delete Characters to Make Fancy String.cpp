// 1957. Delete Characters to Make Fancy String
// https://leetcode.com/problems/delete-characters-to-make-fancy-string/

class Solution {
public:
    string makeFancyString(string s) {
        // if size is less than 3, return it
        if (s.length() < 3) {
            return s;
        }

        int j = 2;
        for (int i = 2; i < s.size(); ++i) {
            // if the current char is not equal to the previously inserted
            // two chars, then we can add it to string
            if (s[i] != s[j-1] || s[i] != s[j-2]) {
                s[j++] = s[i];
            }
        }

        // resize the string to the number of characters added in the string
        // given by j
        s.resize(j);
        return s;
    }
};
