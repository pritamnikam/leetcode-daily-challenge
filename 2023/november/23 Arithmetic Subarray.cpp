// 1630. Arithmetic Subarray
// https://leetcode.com/problems/arithmetic-subarrays


class Solution {
public:
  vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
    vector<bool> ans;
    for (int i = 0; i < l.size(); i++) {
        vector<int> arr(begin(nums) + l[i], begin(nums) + r[i] + 1);
        ans.push_back(check(arr));
    }

    return ans;
  }

private:
  bool check(vector<int>& arr) {
    set<int> arrSet(arr.begin(), arr.end());
    int minElement = INT_MAX, maxElement = MIN_INT;
    for (int num: arr) {
      minElement = min(minElement, num);
      maxElement = max(maxElement, num);
    }

    if ((maxElement - minElement) % (arr.size() - 1) != 0) return false;

    int diff = (maxElement - minElement) / (arr.size() - 1);
    int curr = minElement + diff;

    while (curr < maxElement) {
      if (!arrSet.count(curr)) return false;
      curr += diff;
    }

    return true;
  }
};
