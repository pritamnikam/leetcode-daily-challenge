// 446. Arithmetic Slices II Subsequence
// https://leetcode.com/problems/arithmetic-slices-ii-subsequence/

#define ll long long

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        ll ans = 0;

        // list of sequences starting from 1..n.
        vector<map<ll, int>> count(n);

        // starting from 1..n.
        for (int i = 1; i < n; i++) {
            // starting from 0..i.
            for (int j = 0; j < i; j++) {

                ll difference = (ll) nums[i] - (ll) nums[j];
                int sum  = 0;
                if (count[j].find(difference) != count[j].end()) {
                    sum = count[j][difference];
                }

                count[i][difference] += sum + 1;
                ans += sum;
            }
        }

        return (int)ans;
    }
};
