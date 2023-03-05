/*
28. Find the Index of the First Occurrence in a String
https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string

Given two strings needle and haystack, return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

Example 1:
Input: haystack = "sadbutsad", needle = "sad"
Output: 0
Explanation: "sad" occurs at index 0 and 6.
The first occurrence is at index 0, so we return 0.

Example 2:
Input: haystack = "leetcode", needle = "leeto"
Output: -1
Explanation: "leeto" did not occur in "leetcode", so we return -1.

Constraints:
1 <= haystack.length, needle.length <= 104
haystack and needle consist of only lowercase English characters.

*/

using namespace std;

#include <iostream>
#include <string>
#include <vector>

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
} // namespace

void testFindTheIndexOfFirstOccurrenceInString() {
    string haystack = "sadbutsad", needle = "sad";
    cout << "Find the Index of the First Occurrence in a String: " 
        << Solution().strStr(haystack, needle) << endl;
}