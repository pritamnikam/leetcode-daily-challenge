// 1750. Minimum Length of String After Deleting Similar Ends
// https://leetcode.com/problems/minimum-length-of-string-after-deleting-similar-ends/

class Solution {
public:
    int minimumLength(string s) {
        int begin = 0, end = s.length() - 1;

         // Delete similar ends until the ends differ or they meet in the middle
        while (begin < end && s[begin] == s[end]) {
            char c = s[begin];

            // Delete consecutive occurrences of c from prefix
            while (begin <= end && s[begin] == c) {
                begin++;
            }

            // Delete consecutive occurrences of c from suffix
            while (end > begin && s[end] == c) {
                end--;
            }
        }

        // Return the number of remaining characters
        return end - begin + 1;
    }
};
