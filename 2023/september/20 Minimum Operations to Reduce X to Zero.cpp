// 1658. Minimum Operations to Reduce X to Zero
// https://leetcode.com/problems/minimum-operations-to-reduce-x-to-zero
using namespace std;

#include <iostream>
#include <vector>

class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int total = 0;
        for (int n: nums)
            total += n;
        
        if (x > total) return -1;
        if (x == total) return nums.size();
        
        // (total - x) -> find longest subarray that sum
        int windowStart = 0;
        int windowLength = 0;
        int sum = 0;
        for (int windowEnd = 0; windowEnd < nums.size(); ++windowEnd) {
            sum += nums[windowEnd];
            
            while (sum >= (total - x)) {
                if (sum == (total - x)) {
                    windowLength = max(windowLength, windowEnd - windowStart + 1);
                }
                
                sum -= nums[windowStart];
                windowStart++;
            }
        }
        
        return (windowLength == 0) ? -1 : nums.size() - windowLength;
    }
};
