#include "../header.h"

class Trie {
private:
    Trie *child[26];
    bool isWord;
public:
    Trie(): isWord(false) {
        for (int i = 0; i < 26; ++i) {
            child[i] = nullptr;
        }
    }
    
    void insert(string word) {
        Trie *node = this;
        for (char c: word) {
            int t = c - 'a';
            if (!node->child[t]) {
                node->child[t] = new Trie();
            }
            node = node->child[t];
        }
        node->isWord = true;
    }
    
    bool search(string word) {
        Trie *node = this;
        for (char c: word) {
            int t = c - 'a';
            if (!node->child[t]) {
                return false;
            }
            node = node->child[t];
        }
        return node->isWord;
    }
    
    bool startsWith(string prefix) {
        Trie *node = this;
        for (char c: prefix) {
            int t = c - 'a';
            if (!node->child[t]) {
                return false;
            }
            node = node->child[t];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */