/*
208. Implement Trie (Prefix Tree)
https://leetcode.com/problems/implement-trie-prefix-tree/


A trie (pronounced as "try") or prefix tree is a tree data structure used to efficiently store and 
retrieve keys in a dataset of strings. There are various applications of this data structure, such
as autocomplete and spellchecker.

Implement the Trie class:

Trie() Initializes the trie object.
void insert(String word) Inserts the string word into the trie.
boolean search(String word) Returns true if the string word is in the trie (i.e., was inserted before), 
and false otherwise.
boolean startsWith(String prefix) Returns true if there is a previously inserted string word that has 
the prefix prefix, and false otherwise.


Example 1:

Input
["Trie", "insert", "search", "search", "startsWith", "insert", "search"]
[[], ["apple"], ["apple"], ["app"], ["app"], ["app"], ["app"]]
Output
[null, null, true, false, true, null, true]

Explanation
Trie trie = new Trie();
trie.insert("apple");
trie.search("apple");   // return True
trie.search("app");     // return False
trie.startsWith("app"); // return True
trie.insert("app");
trie.search("app");     // return True


Constraints:

1 <= word.length, prefix.length <= 2000
word and prefix consist only of lowercase English letters.
At most 3 * 104 calls in total will be made to insert, search, and startsWith.

*/

using namespace std;

#include <iostream>
#include <unordered_map>

namespace {
    class Trie {
        unordered_map<char, Trie*> children;
        bool eow;
    public:
        Trie() {
            eow = false;
        }

        void insert(string word) {
            Trie* node = (Trie*)this;
            for (char ch : word) {
                if (!node->children.count(ch)) {
                    node->children[ch] = new Trie;
                }

                node = node->children[ch];
            }

            node->eow = true;
        }

        bool search(string word) {
            Trie* node = serchPrefix(word);
            return node && node->eow;
        }


        bool startsWith(string prefix) {
            return serchPrefix(prefix) != nullptr;
        }

    private:
        Trie* serchPrefix(string word) {
            Trie* node = (Trie*)this;
            for (char ch : word) {
                if (!node->children.count(ch)) {
                    return nullptr;
                }

                node = node->children[ch];
            }

            return node;
        }
    };

    /**
     * Your Trie object will be instantiated and called as such:
     * Trie* obj = new Trie();
     * obj->insert(word);
     * bool param_2 = obj->search(word);
     * bool param_3 = obj->startsWith(prefix);
     */
}