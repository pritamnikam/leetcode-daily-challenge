// 2251. Number of Flowers in Full Bloom
// https://leetcode.com/problems/number-of-flowers-in-full-bloom

using namespace std;

#include <iostream>
#include <vector>
#include <algorithm>

namespace {

class Solution {
public:
  vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
    vector<int> starts, ends, ans;
    for (auto it: flowers) {
      starts.push_back(it[0]);
      ends.push_back(it[1] + 1);
    }

    sort(starts.begin(), starts.end());
    sort(ends.begin(), ends.end());

    for (int person: people) {
      int i = upper_bound(starts.begin(), starts.end(), person) - starts.begin();
      int j = upper_bound(ends.begin(), ends.end(), person) - ends.begin();
      ans.push_back(i - j);
    }

    return ans;
  }
};

} // namespace
