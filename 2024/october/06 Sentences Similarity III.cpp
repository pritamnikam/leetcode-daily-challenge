// 1813. Sentences Similarity III
// https://leetcode.com/problems/sentence-similarity-iii

class Solution {
public:
    bool areSentencesSimilar(string sentence1, string sentence2) {
        // convert sentences into list of words
        stringstream ss1(sentence1), 
                     ss2(sentence2);
        string word;
        vector<string> s1Words, 
                       s2Words;

        while (ss1 >> word) s1Words.push_back(word);
        while (ss2 >> word) s2Words.push_back(word);

        int start = 0, 
            end1 = s1Words.size() - 1, 
            end2 = s2Words.size() - 1;

        // If words in s1 are more than s2, swap them and return the answer.
        if (s1Words.size() > s2Words.size()) {
            return areSentencesSimilar(sentence2, sentence1);
        }

        // find the maximum words matching from beginning
        while (
            start < s1Words.size() &&
            s1Words[start] == s2Words[start]
        ) {
            ++start;
        }

        // Find the maximum words matching in the end.
        while (
            end1 >= 0 && 
            s1Words[end1] == s2Words[end2]
        ) {
            --end1;
            --end2;
        }
        
        // If ends1 index is less than start, then sentence is similar.
        return end1 < start;
    }
};
