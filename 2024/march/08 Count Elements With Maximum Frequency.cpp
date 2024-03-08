// 3005. Count Elements With Maximum Frequency
// https://leetcode.com/problems/count-elements-with-maximum-frequency

class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int, int> freq;
        int max_freq = 0;
        for (int n: nums) {
            freq[n]++;
            max_freq = max(max_freq, freq[n]);
        }

        int answer = 0;
        for (auto& [key, value]: freq) {
            if (value == max_freq) {
                answer += value;
            }
        }

        return answer;
    }
};
