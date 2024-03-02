// 977. Square of Sorted Array
// https://leetcode.com/problems/squares-of-a-sorted-array
class Solution {
    
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> result;
        int left = 0, right = nums.size()-1;
        while (left <= right) {
            int leftSquare = nums[left]*nums[left];
            int rightSquare = nums[right]*nums[right];
            if (leftSquare < rightSquare) {
                result.emplace_back(rightSquare);
                --right;
            } else {
                result.emplace_back(leftSquare);
                ++left;
            }
        }
        
        reverse(result.begin(), result.end());
        return result;
    }
};
