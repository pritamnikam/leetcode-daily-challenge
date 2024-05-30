// 1442. Count Triplets That Can Form Two Arrays of Equal XOR
// https://leetcode.com/problems/count-triplets-that-can-form-two-arrays-of-equal-xor

class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int N = arr.size();
        int count =0;
        int prefix = 0;

        unordered_map<int, int> countMap = {{0,1}}, totalMap;

        for (int i = 0; i < N; i++) {
            prefix ^= arr[i];

            count += countMap[prefix]++ * i - totalMap[prefix];

            totalMap[prefix] += i + 1;
        }
        return count;
    }
};
