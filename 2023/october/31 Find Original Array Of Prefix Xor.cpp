// 2433 Find Original Array Of Prefix Xor
// https://leetcode.com/problems/find-the-original-array-of-prefix-xor/

class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        int n = pref.size();

        vector<int> output;
        output.push_back(pref[0]);
        for (int i = 1; i < n; i++) {
            output.push_back(pref[i] ^ pref[i - 1]);
        }

        return output;
    }
};
