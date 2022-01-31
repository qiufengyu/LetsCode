#include "../header.h"

struct Trie {
    bool isWord;
    Trie *children[26];
    Trie() {
        isWord = false;
        for (int i = 0; i < 26; ++i) {
            children[i] = nullptr;
        }
    }
};

class WordDictionary {
    Trie *root;
public:
    WordDictionary() {
        root = new Trie();
    }
    
    void addWord(string word) {
        Trie *node = root;
        for (char c: word) {
            if (node->children[c - 'a'] == nullptr) {
                node->children[c - 'a'] = new Trie();
            }
            node = node->children[c - 'a'];
        }
        node->isWord = true;
    }
    
    bool search(string word) {
        return find(word, root, 0);
    }
    bool find(const string& word, Trie *node, int pos) {
        if (pos == word.size()) {
            return node->isWord;
        }
        if (word[pos] == '.') {
            for (int i = 0; i < 26; ++i) {
                Trie *n = node->children[i];
                if (n != nullptr && find(word, n, pos + 1)) {
                    return true;
                }
            }
            return false;
        } else {
            Trie *n = node->children[word[pos] - 'a'];
            return (n != nullptr && find(word, n, pos + 1));
        }
    }
};