#include "../header.h"

struct Trie {
    bool isWord;
    Trie* child[26];
    Trie(): isWord{false} {
        for (int i = 0; i < 26; ++i) {
            child[i] = nullptr;
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
            int idx = c - 'a';
            if (node->child[idx] == nullptr) {
                node->child[idx] = new Trie();
            }
            node = node->child[idx];
        }
        node->isWord = true;
    }
    
    bool search(string word) {
        return search2(word, root);        
    }

    bool search2(string const& word, Trie* node) {
        for (int idx = 0; idx < word.size(); ++idx) {
            char c = word[idx];
            if (c == '.') {
                for (int i = 0; i < 26; ++i) {
                    if (node->child[i] != nullptr) {
                        if (search2(word.substr(idx+1), node->child[i])) {
                            return true;
                        }
                    }
                }
                return false;
            } else {
                int j = c - 'a';
                if (node->child[j] == nullptr) {
                    return false;
                }
                node = node->child[j];
            }
        }
        return node->isWord;
    }
};