// 1838. Frequency Of The Most Frequent Element.cpp
// https://leetcode.com/problems/frequency-of-the-most-frequent-element

class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());

        vector<long> prefix;
        prefix.push_back(nums[0]);

        for (int i = 1; i < nums.size(); i++) {
            prefix.push_back(nums[i] + prefix.back());
        }

        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            ans = max(ans, check(
                i,
                k,
                nums,
                prefix
            ));
        }

        return ans;
    }

private:
    int check(
        int i,
        int k,
        vector<int>& nums, 
        vector<long>& prefix
    ) {
        int target = nums[i], 
            left = 0, 
            right = i,
            best = i;

        while (left <= right) {
            int mid = (left + right) / 2;
            long count = i - mid + 1;
            long finalSum = count * target;
            int originalSum = prefix[i] - prefix[mid] + nums[mid];
            int operationsRequired = finalSum - originalSum;

            if (operationsRequired > k) {
                left = mid + 1;
            } else {
                best = mid;
                right = mid - 1;
            }
        }

        return i - best + 1;
    }
};
