// 557. Reverse Words in a String III
// https://leetcode.com/problems/reverse-words-in-a-string-iii/

using namespacce std;

#include <iostream>
#include <string>

namespace {
class Solution {
public:
    string reverseWords(string s) {
      int i = 0, j = 0;
      for (; j < s.length(); ++j) {
        if (s[j] == ' ') {
          reverseWord(s, i, j - 1);
          i = j + 1;
        }
      }
      reverseWord(s, i, j - 1);
      return s;
    }

private:
  void reverseWord(string& s, int i, int j) {
    while (i < j) {
      swap(s[i], s[j]);
      ++i;
      --j;
    }
  }
};
}
