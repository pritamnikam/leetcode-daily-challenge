// 2038. Remove Colored Pieces if Both Neighbors are the Same Color
// https://leetcode.com/problems/remove-colored-pieces-if-both-neighbors-are-the-same-color

using namespace std;

#include <iostream>
#include <string>

namespace {

class Solution {
public:
  bool winnerOfGame(string colors) {
    int a = 0, b = 0;

    for (int i =  1; i < colors.length() - 1; ++i) {
      if (colors[i] == colors[i-1] && colors[i] == colors[i+1]) {
        if (colors[i] == 'A) a++;
        else b++;
      }
    }

    return a > b;
  }
};

} // namespace
