/*
168. Excel Sheet Column Title
https://leetcode.com/problems/excel-sheet-column-title/

Given an integer columnNumber, return its corresponding column title as it appears in an Excel sheet.

For example:
A -> 1
B -> 2
C -> 3
...
Z -> 26
AA -> 27
AB -> 28
...


Example 1:
Input: columnNumber = 1
Output: "A"

Example 2:
Input: columnNumber = 28
Output: "AB"

Example 3:
Input: columnNumber = 701
Output: "ZY"

Constraints:
1 <= columnNumber <= 231 - 1

*/
using namespace std;

#include <iostream>
#include <string>

namespace {
    class Solution {
    public:
        string convertToTitle(int columnNumber) {
            string ans;

            while (columnNumber) {
                columnNumber--;
                // Get the last character and append it at the end of string.
                ans = ans + (char)((columnNumber) % 26 + 'A');
                columnNumber = (columnNumber) / 26;
            }

            // Reverse it, as we appended characters in reverse order.
            reverse(ans.begin(), ans.end());
            return ans;
        }
    };
} // namespace
