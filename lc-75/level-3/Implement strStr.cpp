/*
28. Implement strStr()
https://leetcode.com/problems/implement-strstr/

Implement strStr().

Given two strings needle and haystack, return the index of the first occurrence of needle
in haystack, or -1 if needle is not part of haystack.

Clarification:
What should we return when needle is an empty string? This is a great question to ask
during an interview.

For the purpose of this problem, we will return 0 when needle is an empty string.
This is consistent to C's strstr() and Java's indexOf().



Example 1:

Input: haystack = "hello", needle = "ll"
Output: 2
Example 2:

Input: haystack = "aaaaa", needle = "bba"
Output: -1


Constraints:

1 <= haystack.length, needle.length <= 104
haystack and needle consist of only lowercase English characters.

*/

using namespace std;
#include <iostream>
#include <string>

namespace {

    class Solution {
    public:

        int strStr(string haystack, string needle) {
            if (haystack.empty() ||
                needle.empty() ||
                needle.length() > haystack.length()) {
                return -1;
            }

            int len = haystack.length(),
                i = 0,
                j = 0,
                pos = 0;

            while (i < len && j < needle.length()) {
                if (haystack[i++] == needle[j]) {
                    j++;
                }
                else {
                    i = i - j;
                    j = 0;
                    pos = i;
                }
            }

            return j == needle.length() ? pos : -1;
        }
    };
}

void testImplementstrStr() {
    string haystack = "hello", needle = "ll";
    cout << "Implement strStr(): " << Solution().strStr(haystack, needle) << endl;
}
