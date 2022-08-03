/*
Excel Sheet Column Number

Given a string columnTitle that represents the column title as appear in an Excel sheet, return its corresponding column number.

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

Input: columnTitle = "A"
Output: 1
Example 2:

Input: columnTitle = "AB"
Output: 28
Example 3:

Input: columnTitle = "ZY"
Output: 701


Constraints:

1 <= columnTitle.length <= 7
columnTitle consists only of uppercase English letters.
columnTitle is in the range ["A", "FXSHRXW"].

*/
using namespace std;
#include <vector>
#include <string>
#include <unordered_map>

class Solution {
public:
    int titleToNumber(string columnTitle) {
        int sum = 0;
        for (int i = 0; i < columnTitle.length(); ++i) {
            int index = columnTitle[i] - 'A' + 1;
            sum = sum * 26 + index;
        }

        return sum;
    }
};