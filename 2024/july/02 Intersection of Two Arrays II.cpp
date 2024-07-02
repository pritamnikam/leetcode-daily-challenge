// 350. Intersection of Two Arrays II
// https://leetcode.com/problems/intersection-of-two-arrays-ii
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
  
        vector<int> result;
        int i = 0, j = 0;
        while (i < nums1.size() && j < nums2.size()) {
            if (nums1[i] < nums2[j]) ++i;
            else if (nums1[i] > nums2[j]) ++j;
            else {
                result.emplace_back(nums1[i]);
                ++i; ++j;
            }
        }
        
        return result;
    }

    // It's a good idea to check array sizes and use a hash map for the smaller array.
    // It will reduce memory usage when one of the arrays is very large.
    
    // Time: O(m+n) & Spane: O(min(m, n))
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        // If nums1 is larger than nums2, swap the arrays.
        if (nums1.size() > nums2.size())
            return intersect(nums2, nums1);
        
        unordered_map<int, int> numberFreqMap;
        for (int n: nums1)
            numberFreqMap[n]++;
        
        vector<int> result;
        for (int n: nums2) {
            if (numberFreqMap.count(n)) {
                numberFreqMap[n]--;
                if (numberFreqMap[n] >= 0)
                    result.emplace_back(n);
            }
        }
        
        return result;
    }

};
