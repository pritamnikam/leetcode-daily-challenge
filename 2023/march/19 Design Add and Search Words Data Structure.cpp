/*
211. Design Add and Search Words Data Structure
https://leetcode.com/problems/design-add-and-search-words-data-structure/

Design a data structure that supports adding new words and finding if a string matches any previously added string.

Implement the WordDictionary class:

WordDictionary() Initializes the object.
void addWord(word) Adds word to the data structure, it can be matched later.
bool search(word) Returns true if there is any string in the data structure that matches word or false otherwise. word may contain dots '.' where dots can be matched with any letter.


Example:

Input
["WordDictionary","addWord","addWord","addWord","search","search","search","search"]
[[],["bad"],["dad"],["mad"],["pad"],["bad"],[".ad"],["b.."]]
Output
[null,null,null,null,false,true,true,true]

Explanation
WordDictionary wordDictionary = new WordDictionary();
wordDictionary.addWord("bad");
wordDictionary.addWord("dad");
wordDictionary.addWord("mad");
wordDictionary.search("pad"); // return False
wordDictionary.search("bad"); // return True
wordDictionary.search(".ad"); // return True
wordDictionary.search("b.."); // return True


Constraints:

1 <= word.length <= 25
word in addWord consists of lowercase English letters.
word in search consist of '.' or lowercase English letters.
There will be at most 3 dots in word for search queries.
At most 104 calls will be made to addWord and search.
*/

using namespace std;

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

namespace {

    class TrieNode {
    public:
        bool isCompleteWord;
        TrieNode* children[26];

        TrieNode() {
            isCompleteWord = false; // when the word is complete (mark that node as true)
            memset(children, 0, sizeof(children)); // for 26 possible Childrens (for next letter)
        }
    };

    class WordDictionary {
    public:
        TrieNode* root;
        WordDictionary() {
            root = new TrieNode();
        }

        void addWord(string word) {
            TrieNode* node = root;
            for (char ch : word) {
                int idx = ch - 'a';
                if (node->children[idx] == NULL) node->children[idx] = new TrieNode();
                node = node->children[idx];
            }
            node->isCompleteWord = true;
        }

        bool search(string word) {
            return searchHelper(word, root);
        }

        bool searchHelper(string word, TrieNode* node) {
            for (int i = 0; i < word.length(); i++) {
                char ch = word[i];
                if (ch == '.') {
                    for (auto c : node->children)
                        if (c && searchHelper(word.substr(i + 1), c)) return true;
                    return false;
                }
                int idx = ch - 'a';
                if (node->children[idx] == NULL) return false;
                node = node->children[idx];
            }
            return node->isCompleteWord;
        }
    };

    /**
     * Your WordDictionary object will be instantiated and called as such:
     * WordDictionary* obj = new WordDictionary();
     * obj->addWord(word);
     * bool param_2 = obj->search(word);
     */


}  // namespace


void testDesignAddAndSearchWordDataStructure() {
    /*
        Input
        ["WordDictionary","addWord","addWord","addWord","search","search","search","search"]
        [[],["bad"],["dad"],["mad"],["pad"],["bad"],[".ad"],["b.."]]
        Output
        [null,null,null,null,false,true,true,true]
    */

    WordDictionary wd;
    wd.addWord("bad");
    wd.addWord("dad");
    wd.addWord("mad");

    bool result = wd.search("pad");
    result = wd.search("bad");
    result = wd.search(".ad");
    result = wd.search("b..");
}
