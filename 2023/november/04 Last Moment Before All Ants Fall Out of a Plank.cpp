// 1503. Last Moment Before All Ants Fall Out of a Plank
// https://leetcode.com/problems/last-moment-before-all-ants-fall-out-of-a-plank/


class Solution {
public:
  int getLastMoment(int n, vector<int>& left, vector<int>& right) {
    int ans = 0;
    for (int num: left) ans = max(ans, num);
    for (int num: right) ans = max(ans, n - num);
    return ans;
  }
};
