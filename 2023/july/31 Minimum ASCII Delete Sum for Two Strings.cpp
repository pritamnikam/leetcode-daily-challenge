/*
712. Minimum ASCII Delete Sum for Two Strings
https://leetcode.com/problems/minimum-ascii-delete-sum-for-two-strings

Given two strings s1 and s2, return the lowest ASCII sum of deleted characters to make two strings equal.



Example 1:

Input: s1 = "sea", s2 = "eat"
Output: 231
Explanation: Deleting "s" from "sea" adds the ASCII value of "s" (115) to the sum.
Deleting "t" from "eat" adds 116 to the sum.
At the end, both strings are equal, and 115 + 116 = 231 is the minimum sum possible to achieve this.
Example 2:

Input: s1 = "delete", s2 = "leet"
Output: 403
Explanation: Deleting "dee" from "delete" to turn the string into "let",
adds 100[d] + 101[e] + 101[e] to the sum.
Deleting "e" from "leet" adds 101[e] to the sum.
At the end, both strings are equal to "let", and the answer is 100+101+101+101 = 403.
If instead we turned both strings into "lee" or "eet", we would get answers of 433 or 417, which are higher.


Constraints:

1 <= s1.length, s2.length <= 1000
s1 and s2 consist of lowercase English letters.


*/
using namespace std;

#include <iostream>
#include <vector>
#include <string>

namespace {
    class Solution {
    public:
        int minimumDeleteSum(string s1, string s2) {

            // Make sure s2 is smaller string
            if (s1.length() < s2.length()) {
                return minimumDeleteSum(s2, s1);
            }

            // Case for empty s1
            int m = s1.length(), n = s2.length();
            vector<int> currRow(n + 1);
            for (int j = 1; j <= n; j++) {
                currRow[j] = currRow[j - 1] + s2[j - 1];
            }

            // Compute answer row-by-row
            for (int i = 1; i <= m; i++) {

                int diag = currRow[0];
                currRow[0] += s1[i - 1];

                for (int j = 1; j <= n; j++) {

                    int answer;

                    // If characters are the same, the answer is top-left-diagonal value
                    if (s1[i - 1] == s2[j - 1]) {
                        answer = diag;
                    }

                    // Otherwise, the answer is minimum of top and left values with
                    // deleted character's ASCII value
                    else {
                        answer = min(
                            s1[i - 1] + currRow[j],
                            s2[j - 1] + currRow[j - 1]
                        );
                    }

                    // Before overwriting currRow[j] with answer, save it in diag
                    // for the next column
                    diag = currRow[j];
                    currRow[j] = answer;
                }
            }

            // Return the answer
            return currRow[n];
        }
    };
}
