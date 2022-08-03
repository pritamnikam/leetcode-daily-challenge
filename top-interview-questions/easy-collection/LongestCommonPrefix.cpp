/*
Longest Common Prefix

Write a function to find the longest common prefix string amongst an array of strings.
If there is no common prefix, return an empty string "".

Example 1:
Input: strs = ["flower","flow","flight"]
Output: "fl"

Example 2:
Input: strs = ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.

Constraints:
1 <= strs.length <= 200
0 <= strs[i].length <= 200
strs[i] consists of only lower-case English letters.

*/

using namespace std;

#include <string>
#include <vector>

class Solution {
public:
    // Divide & Conquer
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return string();
        return longestCommonPrefix(strs, 0, strs.size() - 1);
    }

    string longestCommonPrefix(vector<string>& strs, int start, int end) {
        if (start == end) {
            return strs[start];
        }

        int mid = start + (end - start) / 2;
        string left = longestCommonPrefix(strs, start, mid);
        string right = longestCommonPrefix(strs, mid + 1, end);

        return longestCommonPrefix(left, right);
    }

    string longestCommonPrefix(string& str1, string& str2) {
        int i = 0;
        while (i < min(str1.length(), str2.length())) {
            if (str1[i] != str2[i]) {
                break;
            }

            ++i;
        }

        return str1.substr(0, i);
    }
};