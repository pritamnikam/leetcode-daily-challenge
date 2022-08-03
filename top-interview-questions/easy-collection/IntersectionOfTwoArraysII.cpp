/*
Intersection of Two Arrays II

Given two integer arrays nums1 and nums2, return an array of their intersection. 
Each element in the result must appear as many times as it shows in both arrays and you may return the result in any order.

Example 1:
Input: nums1 = [1,2,2,1], nums2 = [2,2]
Output: [2,2]

Example 2:
Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
Output: [4,9]
Explanation: [9,4] is also accepted.


Constraints:
1 <= nums1.length, nums2.length <= 1000
0 <= nums1[i], nums2[i] <= 1000


Follow up:
What if the given array is already sorted? How would you optimize your algorithm?
What if nums1's size is small compared to nums2's size? Which algorithm is better?
What if elements of nums2 are stored on disk, and the memory is limited such that you cannot load all elements into the memory at once?


Follow up:
What if the given array is already sorted? How would you optimize your algorithm?
Solution 1, i.e., sorting, would be better since it does not need extra memory.

What if nums1’s size is small compared to num2’s size? Which algorithm is better?
If two arrays are sorted, we could use binary search, i.e., for each element in the shorter array, search in the longer one. So the overall time complexity is O(nlogm), where n is the length of the shorter array, and m is the length of the longer array. Note that this is better than Solution 1 since the time complexity is O(n + m) in the worst case.


What if elements of nums2 are stored on disk, and the memory is limited such that you cannot load all elements into the memory at once?
If the two arrays have relatively the same length, we can use external sort to sort out the two arrays in the disk. Then load chunks of each array into the memory and compare, by using the method 1.
If one array is too short while the other is long, in this case, if memory is limited and nums2 is stored in disk, partition it and send portions of nums2 piece by piece. keep a pointer for nums1 indicating the current position, and it should be working fine~
Another method is, store the larger array into disk, and for each element in the shorter array, use “Exponential Search” and search in the longer array.

*/

using namespace std;

#include <vector>
#include <unordered_map>

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> map;
        for (int n : nums1) {
            map[n]++;
        }

        vector<int> result;
        for (int n : nums2) {
            auto it = map.find(n);
            if (it != map.end()) {
                int count = it->second;
                if (count) {
                    map[n]--;
                    result.push_back(n);
                }
            }
        }

        return result;
    }

    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        vector<int> result;
        int i = 0, j = 0;
        while (i < nums1.size() && j < nums2.size()) {
            if (nums1[i] == nums2[j]) {
                result.push_back(nums1[i]);
                i++;
                j++;
            }
            else if (nums1[i] < nums2[j]) {
                i++;
            }
            else {
                j++;
            }
        }

        return result;
    }
};