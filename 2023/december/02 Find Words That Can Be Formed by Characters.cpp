// 1160. Find Words That Can Be Formed by Characters 
// https://leetcode.com/problems/find-words-that-can-be-formed-by-characters/

class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        unordered_map<char, int> freq;
        for (char ch: chars) freq[ch]++;

        int answer = 0;
        for (string& word: words) {
            unordered_map<char, int> wordFreq;
            for (char ch: word) wordFreq[ch]++;

            bool matched = true;
            for (auto& [ch, count]: wordFreq) {
                if (freq[ch] < count) {
                    matched = false;
                    break;
                }
            }

            if (matched) answer += word.size();
        }
        return answer;
    }
};
