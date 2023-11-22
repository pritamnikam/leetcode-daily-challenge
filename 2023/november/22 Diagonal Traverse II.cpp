// 1424. Diagonal Traverse II
// https://leetcode.com/problems/diagonal-traverse-ii

class Solution {
public:
  vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
    queue<pair<int, int>> queue;
    vector<int> answer;

    queue.push({0, 0});

    while (!queue.empty()) {
      auto [row, col] = queue.front();
      queue.pop();

      answer.push_back(nums[row][col]);

      if (col == 0 && row + 1 < nums.size()) {
        queue.push({row + 1, col});
      }

      if (col + 1 < nums[row].size()) {
        queue.push({row, col + 1});
      }
    }

    return answer;
  }
};
