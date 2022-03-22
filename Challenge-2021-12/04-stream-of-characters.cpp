#include "../header.h"

struct Trie {
    Trie *children[26];
    bool end;
    Trie() {
        end = false;
        memset(children, 0, sizeof(children));
    }
};

class StreamChecker {
    Trie *root;
    string current;
public:
    StreamChecker(vector<string>& words) {
        root = new Trie();
        for (auto const& word: words) {
            Trie* t = root;
            for (int i = word.size()-1; i >= 0; --i) {
                int index = word[i] - 'a';
                if (t->children[index] == nullptr) {
                    t->children[index] = new Trie();
                }
                t = t->children[index];
            }
            t->end = true;
        }
    }
    
    bool query(char letter) {
        current += letter;
        Trie* t = root;
        for (int i = current.size() - 1; i >= 0; --i) {
            int index = current[i] - 'a';
            if (t->children[index] == nullptr) {
                return false;
            } else {
                t = t->children[index];
                if (t->end) {
                    return true;
                }
            }
        }
        return false;
    }
};