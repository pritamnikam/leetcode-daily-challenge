// 884. Uncommon Words From Two Sentences
// https://leetcode.com/problems/uncommon-words-from-two-sentences

class Solution {
    vector<string> words(string& input) {
        std::stringstream ss(input);
        std::string word;
        std::vector<std::string> words;

        while (std::getline(ss, word, ' ')) {
            words.push_back(word);
        }
        return words;
    }
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string, int> wordCount;
        for (string& s: words(s1)) {
            wordCount[s]++;
        }

        for (string& s: words(s2)) {
            wordCount[s]++;
        }

        vector<string> result;
        for (auto& [k, v]: wordCount) {
            if (v == 1) {
                result.push_back(k);
            }
        }

        return result;
    }
};
