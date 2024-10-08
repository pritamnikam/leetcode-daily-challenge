// 1963. Minimum Number of Swaps to Make the String Balanced
// https://leetcode.com/problems/minimum-number-of-swaps-to-make-the-string-balanced

class Solution {
public:
    int minSwaps(string s) {
        int n = s.size();
        int stackSize = 0;

        for (int i = 0; i < n; i++) {
            char ch = s[i];
            if (ch == '[') {
                stackSize++;
            } else if (stackSize > 0) {
                stackSize--;                
            }
        }
        return (stackSize + 1 )/ 2;
    }
};
