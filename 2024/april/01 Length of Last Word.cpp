// 58. Length of Last Word
// https://leetcode.com/problems/length-of-last-word/

class Solution {
public:
    int lengthOfLastWord(string s) {
        //Remove trailing spaces
        int i = s.size() - 1;
        while (i >= 0) {
            if (s[i] != ' ') break;
            --i;
        }

        // loop until a white space encounters
        int j = i;
        while (j >= 0) {
            if (s[j] == ' ') break;
            --j;
        }

        return i - j;
    }
};
