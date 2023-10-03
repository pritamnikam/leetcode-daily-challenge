using namespace std;

#include <iostream>
#include <unorderd_map>
#include <algorithm>

namespace {

class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        return accumulate(
            nums.begin(), 
            nums.end(), 
            0, 
            [count = unordered_map<int, int> {}] (auto x, auto y) mutable {
              return x + count[y]++;
          });
    }
private:
    int numIdenticalPairsElaboration(vector<int>& A) {
        int ans = 0;
        unordered_map<int, int> cnt;
        for (int x: A) {
        ans += cnt[x]++;
        }
        return ans;
    }
};

} // namespace
