// 1455. check-if-a-word-occurs-as-a-prefix-of-any-word-in-a-sentence
// https://leetcode.com/problems/check-if-a-word-occurs-as-a-prefix-of-any-word-in-a-sentence

class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        int currentWordPosition = 1, 
            currentIndex = 0, 
            sentenceLength = sentence.length();

        while (
            currentIndex < sentenceLength
        ){
            // skip leading spaces
            while (
                currentIndex < sentenceLength &&
                sentence[currentIndex] == ' '
            ) {
                ++currentIndex;
                ++currentWordPosition;
            }


            // check if current word start with the seachword
            int matchCount = 0;
            while (
                currentIndex < sentenceLength &&
                matchCount < searchWord.length() &&
                sentence[currentIndex] == searchWord[matchCount]
            ) {
                ++currentIndex;
                ++matchCount;
            }

            if (matchCount == searchWord.length()) {
                return currentWordPosition;
            }

            // move to the end of word
            while (
                currentIndex < sentenceLength &&
                sentence[currentIndex] != ' '
            ) {
                currentIndex++;
            }
        }

        return -1;
    }
};
