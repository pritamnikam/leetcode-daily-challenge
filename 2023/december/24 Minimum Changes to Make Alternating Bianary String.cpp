// 1758. Minimum Changes to Make Alternating Bianary String
// https://leetcode.com/problems/minimum-changes-to-make-alternating-binary-string

class Solution {
public:
    int minOperations(string s) {
        int start0 = 0, start1= 0;

        for (int i = 0; i < s.size(); i++) {
            // Even length
            if (i % 2 == 0) {
                if (s[i] == '0') { ++start1; }
                else { ++start0; }
            } else { // odd length
                if (s[i] == '1') { ++start1; }
                else { ++start0; }
            }
        }

        return min(start0, start1);
    }
};
