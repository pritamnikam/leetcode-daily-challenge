// 1310. XOR Queries of a Subarray
// https://leetcode.com/problems/xor-queries-of-a-subarray

class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> result;

        // step 1: Convert arr into an-place prefix XOR array
        for (int i = 1; i < arr.size(); ++i) {
            arr[i] ^= arr[i - 1];
        }

        // Step 2: Resolve each query using the prefix XOR array
        for (const auto& q: queries) {
            if (q[0] > 0) {
                result.push_back(
                    arr[q[0] - 1] ^ arr[q[1]]
                );
            } else {
                result.push_back(arr[q[1]]);
            }
        }
        return result;
    }
};
