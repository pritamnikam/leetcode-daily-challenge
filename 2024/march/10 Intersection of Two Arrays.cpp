// 349. Intersection of Two Arrays
// https://leetcode.com/problems/intersection-of-two-arrays/

class Solution {
public:
    // Two set: Space & Time O(m+n)
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> s1, s2;
        
        for (int n: nums1)
            s1.insert(n);
        
        for (int n: nums2)
            s2.insert(n);
        
        if (s1.size() < s2.size())
            return intersection(s1, s2);
        
        return intersection(s2, s1);
    }
    
    vector<int> intersection(unordered_set<int>& s1, unordered_set<int>& s2) {
        vector<int> result;
        for (int entry: s1) {
            if (s2.count(entry))
                result.emplace_back(entry);
        }
        
        return result;
    }
};
