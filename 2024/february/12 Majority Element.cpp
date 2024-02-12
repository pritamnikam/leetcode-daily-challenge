// 169. Majority Element
// https://leetcode.com/problems/majority-element

class Solution {
public:
    int majorityElementHashMap(vector<int>& nums) {
        unordered_map<int, int> numberCounts;
        for (int n: nums) {
            numberCounts[n]++;
        }
        int answer = 0;
        for (auto& [key, value]: numberCounts) {
            if (value > nums.size()/2) {
                answer = key;
                break;
            }
        }
        return answer;
    }

    int majorityElement(vector<int>& nums) {
        int count = 0, candidate = 0;
        for (int n: nums) {
            if (count == 0) {
                candidate = n;
            }
            if (n == candidate) {
                count++;
            }
            else {
                count--;
            }
        }
        return candidate;
    }
};
