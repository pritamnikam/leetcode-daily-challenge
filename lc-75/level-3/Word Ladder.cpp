/*
127. Word Ladder
https://leetcode.com/problems/word-ladder/

A transformation sequence from word beginWord to word endWord using a dictionary wordList is a sequence
of words beginWord -> s1 -> s2 -> ... -> sk such that:

Every adjacent pair of words differs by a single letter.
Every si for 1 <= i <= k is in wordList. Note that beginWord does not need to be in wordList.
sk == endWord
Given two words, beginWord and endWord, and a dictionary wordList, return the number of words in the
shortest transformation sequence from beginWord to endWord, or 0 if no such sequence exists.

Example 1:
Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log","cog"]
Output: 5
Explanation: One shortest transformation sequence is "hit" -> "hot" -> "dot" -> "dog" -> cog", which is 5 words long.

Example 2:
Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log"]
Output: 0
Explanation: The endWord "cog" is not in wordList, therefore there is no valid transformation sequence.


Constraints:
1 <= beginWord.length <= 10
endWord.length == beginWord.length
1 <= wordList.length <= 5000
wordList[i].length == beginWord.length
beginWord, endWord, and wordList[i] consist of lowercase English letters.
beginWord != endWord
All the words in wordList are unique.

*/

using namespace std;

#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include <queue>

namespace {
    class Solution {
    public:
        int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
            

            // base case:
            if (beginWord == endWord) return 0;

            unordered_set<string> set(wordList.begin(), wordList.end());
            if (!set.count(endWord))
                return 0;

            // BFS: level-order traversal
            queue<string> queue;
            queue.push(beginWord);

            // COUNT NUMBER OF WORDS TRANSFORMED
            int level = 1;

            while (!queue.empty()) {
                int size = queue.size();

                // FOR ALL WORDS THIS ROUND
                for (int i = 0; i < size; ++i) {
                    string word = queue.front();
                    queue.pop();

                    // for all char in word
                    for (int j = 0; j < word.length(); ++j) {

                        char originalChar = word[j];

                        for (char ch = 'a'; ch <= 'z'; ++ch) {
                            if (originalChar == ch) continue;

                            word[j] = ch;
                            if (endWord == word) return 1 + level;
                            if (!set.count(word)) continue;
                            set.erase(word);
                            queue.push(word);
                        } // ch-for

                        // HAVE TO UNDO FOR NEXT CHANGE OF LETTER
                        word[j] = originalChar;
                    } // j-for
                } // level-for

                // THIS ROUND ENDS WITH ONE LETTER CHANGED
                ++level;

            } // queue-while

            return 0;
        }
    };
}  // namespace

void testWordLadder() {
    string beginWord = "hit", endWord = "cog";
    vector<string> wordList = { "hot", "dot", "dog", "lot", "log", "cog" };

    cout << "Word Ladder: " << Solution().ladderLength(beginWord, endWord, wordList) << endl;
}