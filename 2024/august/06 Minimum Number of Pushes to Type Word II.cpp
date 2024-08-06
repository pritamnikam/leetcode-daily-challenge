// 3016. Minimum Number of Pushes to Type Word II
// https://leetcode.com/problems/minimum-number-of-pushes-to-type-word-ii/

class Solution {
public:
    int minimumPushes(string word) {
        int count = 0;
        vector<int> freq(26, 0);
        for (auto it: word) {
            freq[it - 'a']++;
        }

        // descending order
        sort(freq.begin(), freq.end(), greater<>());

        for (int i = 0; i < 26; i++) {
            if (i < 8) {
                count += freq[i];
            }

            else if (i < 16) {
                count += freq[i] * 2;
            }

            else if (i < 24) {
                count += freq[i] * 3;
            }

            else {
                count += freq[i] * 4;
            }
        }
        return count;
    }
};
