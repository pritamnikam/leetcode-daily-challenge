// 2825. make-string-a-subsequence-using-cyclic-increments
// https://leetcode.com/problems/make-string-a-subsequence-using-cyclic-increments

class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        int str2Index = 0;
        int lengthStr1 = str1.size(), lengthStr2 = str2.size();

        // traverse through both the strings using a for loop

        for (
            int str1Index = 0; 
            str1Index < lengthStr1 && str2Index < lengthStr2;
            ++str1Index
        ) {
            // check if chars match, or if str1 increment to str2
            if (
                str1[str1Index] == str2[str2Index] ||
                str1[str1Index] + 1 == str2[str2Index] ||
                str1[str1Index] - 25 == str2[str2Index]
            ) {
                str2Index++;
            }
        }

        // check if all chars in str2 were matched
        return str2Index == lengthStr2; 
    }
};
