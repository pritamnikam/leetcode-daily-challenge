// 648. Replace Words
// https://leetcode.com/problems/replace-words

class TrieNode {
public:
    bool isEnd;
    vector<TrieNode*> children;

    TrieNode() : children(26, nullptr) { isEnd = false; }
};

class Trie {
private:
    TrieNode* root;

public:
    Trie() { root = new TrieNode(); }

    void insert(string word) {
        TrieNode* current = root;
        for (char c : word) {
            if (current->children[c - 'a'] == nullptr) {
                current->children[c - 'a'] = new TrieNode();
            }
            current = current->children[c - 'a'];
        }
        current->isEnd = true;
    }

    // Find the shortest root of the word in the trie
    string shortestRoot(string word) {
        TrieNode* current = root;
        for (int i = 0; i < word.length(); ++i) {
            char c = word[i];
            if (current->children[c - 'a'] == nullptr) {
                // There is not a corresponding root in the trie
                return word;
            }
            current = current->children[c - 'a'];
            if (current->isEnd) {
                return word.substr(0, i + 1);
            }
        }
        // There is not a corresponding root in the trie
        return word;
    }
};

class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        istringstream ss(sentence);
        Trie dicTrie;
        for (string word: dictionary) {
            dicTrie.insert(word);
        }


        string word;
        string newSentence;
        while (getline(ss, word, ' ')) {
            newSentence += dicTrie.shortestRoot(word) + " ";
        }

        newSentence.pop_back();
        return newSentence;
    }
};
