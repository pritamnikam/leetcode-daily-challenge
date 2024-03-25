// 442. Find All Duplicates in an Array
// https://leetcode.com/problems/find-all-duplicates-in-an-array

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> mp;
        for (int n: nums)
            mp[n]++;
        
        vector<int> answer;
        for (auto it: mp)
            if (it.second > 1)
                answer.emplace_back(it.first);
        
        return answer;
    }
};
