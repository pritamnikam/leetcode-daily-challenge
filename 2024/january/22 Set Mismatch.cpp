// 645. Set Mismatch
// https://leetcode.com/problems/set-mismatch/description/


class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int i = 0;
        while (i < nums.size()) {
            if (nums[i] != nums[nums[i]-1]){
                swap(nums[i], nums[nums[i]-1]);
            } else{
                ++i;
            }
        }
        
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != i+1)
                return {nums[i], i +1};            
        }
    
        return {-1, -1};
    }
};
