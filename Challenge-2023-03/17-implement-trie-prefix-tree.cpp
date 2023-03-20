#include "../header.h"

class Trie {
    Trie *child[26];
    bool isWord;
public:
    Trie(): isWord{false} {
        for (int i = 0; i < 26; ++i) {
            child[i] = nullptr;
        }
    }
    
    void insert(string word) {
        Trie *node = this;
        for (char c: word) {
            int idx = c - 'a';
            if (node->child[idx] == nullptr) {
                node->child[idx] = new Trie();
            }
            node = node->child[idx];
        }
        node->isWord = true;
    }
    
    bool search(string word) {
        return getPrefix(word) == 1;        
    }

    bool startsWith(string prefix) {
        return getPrefix(prefix) >= 0;
    }
    
    int getPrefix(string prefix) {
        Trie *node = this;
        for (char c: prefix) {
            int idx = c - 'a';
            if (node->child[idx] == nullptr) {
                return -1;
            }
            node = node->child[idx];
        }
        if (node->isWord) {
            return 1;
        }
        return 0;
    }
};