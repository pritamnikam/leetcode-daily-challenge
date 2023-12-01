// 1662. Check if Two String Arrays are Equivalent
// https://leetcode.com/problems/check-if-two-string-arrays-are-equivalent/d

class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        int word1Pointer = 0, word2Pointer = 0;
        int string1Pointer = 0, string2Pointer = 0;

        while (word1Pointer < word1.size() && word2Pointer < word2.size()) {
            if (word1[word1Pointer][string1Pointer++] != word2[word2Pointer][string2Pointer++]) {
                return false;
            }

            if (word1[word1Pointer].size() == string1Pointer) {
                word1Pointer++;
                string1Pointer = 0;
            }

            if (word2[word2Pointer].size() == string2Pointer) {
                word2Pointer++;
                string2Pointer = 0;
            }
        }

        return word1Pointer == word1.size() 
            && word2Pointer == word2.size();
    }
};
