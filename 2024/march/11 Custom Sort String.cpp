// 791. Custom Sort String
// https://leetcode.com/problems/custom-sort-string/

class Solution {
public:
    string customSortString(string order, string s) {
        unordered_map<char ,int> freq;
        for (char ch: order) {
            freq[ch] = 0;
        }

        for (char ch: s) {
            if (freq.find(ch) != freq.end()) {
                freq[ch]++;
            }
        }

        string orderSequence;
        for (char ch: order) {
            orderSequence.append(freq[ch], ch);
        }

        for (char ch: s) {
            if (freq.find(ch) == freq.end()) {
                orderSequence.push_back(ch);
            }
        }

        return orderSequence;
    }
};
