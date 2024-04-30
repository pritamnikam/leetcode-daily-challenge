// 1915. Number of Wonderful Substrings
// https://leetcode.com/problems/number-of-wonderful-substrings/

class Solution {
public:
    long long wonderfulSubstrings(string word) {
        int N = word.length();

        // create a frequency map
        // key -> bitmask, value -> freq. of bitmask key

        unordered_map<int, int> freq;
        freq[0] = 1;

        int mask = 0;
        long long result = 0L;

        for (int i = 0; i < N; i++) {
            char ch = word[i];
            int bit = ch - 'a';

            mask ^= (1 << bit);
            result += freq[mask];
            freq[mask]++;

            for (int odd_ch = 0 ; odd_ch < 10; odd_ch++) {
                result += freq[mask ^ (1 << odd_ch)];
            }
        }

        return result;
    }
};
