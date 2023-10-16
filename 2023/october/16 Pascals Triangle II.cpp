// Pascal's Triangle II
// 

using namespace std;

#include <iostream>
#include <vector>

namespace {
  class Solution {
  public:
    vector<int> getRow(int rowNumber) {
      vector<int> cur, prev = { 1 };

      for (int i = 1; i <= rowNumber; i++) {

        cur.assign(i + 1, 1);
        for (int j = 1; j < i; j++) {
          cur[j] = prev[j - 1] + prev[j]; 
        }

        prev = move(cur);
      }

      return prev;
    }
  };
} // namespace
