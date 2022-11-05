/*
212. Word Search II
https://leetcode.com/problems/word-search-ii/

Given an m x n board of characters and a list of strings words, return all words on the board.

Each word must be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once in a word.

Example 1:
Input: board = [["o","a","a","n"],["e","t","a","e"],["i","h","k","r"],["i","f","l","v"]], words = ["oath","pea","eat","rain"]
Output: ["eat","oath"]

Example 2:
Input: board = [["a","b"],["c","d"]], words = ["abcb"]
Output: []

Constraints:
m == board.length
n == board[i].length
1 <= m, n <= 12
board[i][j] is a lowercase English letter.
1 <= words.length <= 3 * 104
1 <= words[i].length <= 10
words[i] consists of lowercase English letters.
All the strings of words are unique.
*/

using namespace std;

#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

namespace {

    struct TrieNode {
        unordered_map<char, TrieNode*> children;
        string word;
    };

    class Solution {
    public:
        vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
            // 1. build trie
            TrieNode root;
            buildTrie(words, &root);

            // 2. perform backtracking:
            return performBacktrack(board, &root);
        }

        void buildTrie(vector<string>& words, TrieNode* root) {
            for (string word : words) {
                TrieNode* node = root;
                for (char ch : word) {
                    if (node->children.count(ch)) {
                        node = node->children[ch];
                    }
                    else {
                        node = new TrieNode;
                        node->children[ch] = node;
                    }
                }

                node->word = word;  // store words in Trie
            }
        }

        vector<string> performBacktrack(vector<vector<char>>& board, TrieNode* root) {
            vector<string> result;
            for (int i = 0; i < board.size(); ++i) {
                for (int j = 0; j < board[0].size(); ++j) {
                    if (root->children.count(board[i][j])) {
                        backtrack(board, i, j, root, result);
                    }
                }
            }

            return result;
        }

        // up, right, down, left
        vector< vector<int>> directions{ {-1,0}, {0, 1}, {1,0}, {0,-1} };

        void backtrack(vector<vector<char>>& board,
            int i, int j, TrieNode* root,
            vector<string>& result) {
            // get the letter from the board
            char letter = board[i][j];
            TrieNode* currNode = root->children[letter];

            // check if there is any match
            if (!currNode->word.empty()) {
                result.push_back(currNode->word);
                currNode->word = "";
            }

            // mark the current letter before the EXPLORATION
            board[i][j] = '#';

            for (auto d : directions) {
                int x = d[0] + i, y = d[1] + j;
                if (!isValid(board, x, y) ||
                    !root->children.count(board[x][y])) {
                    continue;
                }

                backtrack(board, x, y, currNode, result);
            }

            // End of EXPLORATION, restore the original letter in the board.
            board[i][j] = letter;
        }

        bool isValid(vector<vector<char>>& board, int row, int col) {
            return row >= 0 && row < board.size() && col >= 0 && col < board[0].size();
        }
    };
}

void testWordSearchII() {
    // Input: board = [["a","b"],["c","d"]], words = ["abcb"]
    // Output: []

    vector<vector<char>> board = { {"a", "b"} , { "c", "d" }};
    vector<string> words = { "abcb" };

    vector<string> result = Solution().findWords(board, words);
}
