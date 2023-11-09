// 1759. Count Number of Homogenous Strings
// https://leetcode.com/problems/count-number-of-homogenous-substrings

using namespace std;

#include <iostream>
#include <vector>

class Solution {
public:
  int countHomogenous(string& s) {
   int answer = 0, countStreak = 0;
    const int MOD = 1e9 + 7;

    for (int i = 0; i < s.size(); i++) {
      if (i == 0 || s[i] == s[i - 1]) currentStreak++;
      else currentStreak = 1;
      answer = (answer + currentStreak) % MOD;
    }

    return answer;
  }
};
