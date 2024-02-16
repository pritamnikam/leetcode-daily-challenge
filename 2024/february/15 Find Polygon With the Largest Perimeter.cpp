// 2971. Find Polygon With the Largest Perimeter
// https://leetcode.com/problems/find-polygon-with-the-largest-perimeter/

class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        long long previousElementSum = 0;
        long long answer = -1;

        for (int i = 0; i < nums.size(); i++) {
            if (i >= 2 && nums[i] < previousElementSum) {
                answer = nums[i] + previousElementSum;
            }
            previousElementSum += nums[i];
        }
        return answer;
    }
};
