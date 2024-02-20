// 268. Missing Number
// https://leetcode.com/problems/missing-number


class Solution {
private:
	void swap(vector<int>& nums, int i, int j) {
		int k = nums[i];
		nums[i] = nums[j];
		nums[j] = k;
	}

public:
	// cycle sort: sort in range [1-n]
	int missingNumber(vector<int>& nums) {
		int i = 0;

		// numbers that are not at there correct place in range [1-n]
		while (i < nums.size()) {
			if (nums[i] < nums.size() && 
				nums[i] != nums[nums[i]]) {
				swap(nums, i, nums[i]);
			}
			else {
				++i;
			}
		}

		// numbers not at their right place - missing number
		for (int i = 0; i < nums.size(); ++i) {
			if (nums[i] != i)
				return i;
		}

		return nums.size();
	}
};
