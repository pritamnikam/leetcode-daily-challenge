/*
1802. Maximum Value at a Given Index in a Bounded Array
https://leetcode.com/problems/maximum-value-at-a-given-index-in-a-bounded-array

You are given three positive integers: n, index, and maxSum. You want to construct an array nums (0-indexed) that satisfies the following conditions:

nums.length == n
nums[i] is a positive integer where 0 <= i < n.
abs(nums[i] - nums[i+1]) <= 1 where 0 <= i < n-1.
The sum of all the elements of nums does not exceed maxSum.
nums[index] is maximized.
Return nums[index] of the constructed array.

Note that abs(x) equals x if x >= 0, and -x otherwise.

 

Example 1:

Input: n = 4, index = 2,  maxSum = 6
Output: 2
Explanation: nums = [1,2,2,1] is one array that satisfies all the conditions.
There are no arrays that satisfy all the conditions and have nums[2] == 3, so 2 is the maximum nums[2].
Example 2:

Input: n = 6, index = 1,  maxSum = 10
Output: 3
 

Constraints:

1 <= n <= maxSum <= 109
0 <= index < n

*/

namespace {
class Solution {
public:
    long long c(long long n){
        return (n*(n+1))/2;
    }
    int maxValue(int n, int index, int maxSum) {
        long long l=1,r=maxSum;
        long long ans=1;
        while(l<=r){
            long long mid=(l+r)/2;
            long long left = c(mid-1);
            if(index>mid-1){
                left += (index-mid+1);
            }
            else left -= c(mid-1-index);
            long long right = c(mid-1) ;
            if((n-1-index)>(mid-1)){
                right += (n-1-index-(mid-1));
            }
            else right -= c(mid-1-(n-1-index));
            if(left+right<=(maxSum-mid)){
                ans=mid;
                l=mid+1;
            }
            else r=mid-1;
        }   
        return ans;
    }
};
}
