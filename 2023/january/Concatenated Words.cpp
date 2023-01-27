/*
472. Concatenated Words
https://leetcode.com/problems/concatenated-words/

Given an array of strings words (without duplicates), return all the concatenated words in the given list of words.

A concatenated word is defined as a string that is comprised entirely of at least two shorter words in the given array.

Example 1:
Input: words = ["cat","cats","catsdogcats","dog","dogcatsdog","hippopotamuses","rat","ratcatdogcat"]
Output: ["catsdogcats","dogcatsdog","ratcatdogcat"]
Explanation: "catsdogcats" can be concatenated by "cats", "dog" and "cats";
"dogcatsdog" can be concatenated by "dog", "cats" and "dog";
"ratcatdogcat" can be concatenated by "rat", "cat", "dog" and "cat".

Example 2:
Input: words = ["cat","dog","catdog"]
Output: ["catdog"]


Constraints:
1 <= words.length <= 104
1 <= words[i].length <= 30
words[i] consists of only lowercase English letters.
All the strings of words are unique.
1 <= sum(words[i].length) <= 105


[Solution]
Steps:
- Put all the words into a HashSet as a dictionary.
- Create an empty list answer.
- For each word in the words create a boolean array dp of length = word.length + 1, and set dp[0] = true.
- For each index i from 1 to word.length, set dp[i] to true if we can find a value j from 0 (1 if i == word.length) such that dp[j] = true and word.substring(j, i) is in the dictionary.
- Put word into answer if dp[word.length] = true.
- After processing all the words, return answer.
*/

using namespace std;

#include <iostream>
#include <vector>
#include <unordered_set>

namespace {
    class Solution {
    public:
        vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
            unordered_set<string> dictionary(words.begin(), words.end());
            vector<string> answer;

            for (const string& word : words) {
                const int length = word.length();
                vector<bool> dp(length + 1);
                dp[0] = true;

                for (int i = 1; i <= length; ++i) {
                    for (int j = (i == length ? 1 : 0); !dp[i] && j < i; ++j) {
                        dp[i] = dp[j] && dictionary.count(word.substr(j, i - j));
                    }
                }

                if (dp[length]) {
                    answer.push_back(word);
                }
            }

            return answer;
        }
    };

    class SolutionDFS {
        bool dfs(
            const string& word, 
            int length,
            vector<bool>& visited,
            const unordered_set<string>& dictionary) {
            if (length == word.length()) {
                return true;
            }
            if (visited[length]) {
                return false;
            }
            visited[length] = true;
            for (int i = word.length() - (length == 0 ? 1 : 0); i > length; --i) {
                if (dictionary.count(word.substr(length, i - length)) &&
                    dfs(word, i, visited, dictionary)) {
                    return true;
                }
            }
            return false;
        }

    public:
        vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
            unordered_set<string> dictionary(words.begin(), words.end());
            vector<string> answer;
            for (const string& word : words) {
                vector<bool> visited(word.length());
                if (dfs(word, 0, visited, dictionary)) {
                    answer.push_back(word);
                }
            }
            return answer;
        }
    };
}  // namespace

void testConcatenatedWords() {
    /*
        Example 1:
        Input: words = ["cat","cats","catsdogcats","dog","dogcatsdog","hippopotamuses","rat","ratcatdogcat"]
        Output: ["catsdogcats","dogcatsdog","ratcatdogcat"]
    */
    vector<string> words = { "cat", "cats", "catsdogcats", "dog", "dogcatsdog", "hippopotamuses", "rat", "ratcatdogcat" };
    vector<string> answers = Solution().findAllConcatenatedWordsInADict(words);
}
