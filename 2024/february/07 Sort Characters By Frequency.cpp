// 451. Sort Characters By Frequency
// https://leetcode.com/problems/sort-characters-by-frequency

class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> map;
        priority_queue<pair<int, char>> heap;

        for(char ch: s) map[ch]++;

        for (auto& it: map) {
            int freq = it.second;
            char ch = it.first;

            heap.push({ freq, ch });
        }

        string output;
        while(!heap.empty()) {
            auto [freq, ch] = heap.top();
            heap.pop();

            for (int i = 0; i < freq; ++i) {
                output += ch;
            }
        }

        return output;
    }
};
