#include "../header.h"

const int R = 26;

class TrieNode {
private:
    TrieNode *links[R];
    bool isEnd;
public:
    TrieNode() {
        isEnd = false;
        for (int i = 0; i < R; i++) {
            links[i] = nullptr;
        }
    }
    bool containsKey(char ch) {
        return links[ch - 'a'] != nullptr;
    }
    TrieNode* get(char ch) {
        return links[ch - 'a'];
    }
    void put(char ch, TrieNode* node) {
        links[ch - 'a'] = node;
    }
    void setEnd() {
        isEnd = true;
    }
    bool getEnd() {
        return isEnd;
    }
    TrieNode** getLinks() {
        return links;
    }
};

class WordDictionary {
private:
    TrieNode *root;
    bool searchWord(string& word, TrieNode *n, int pos) {
        // cout << "search " << word << " at " << pos << ": " << word[pos] << endl;
        if (pos == word.length()) {
            return n->getEnd();
        }
        TrieNode** links = n->getLinks();
        if (word[pos] == '.') {            
            for (int i = 0; i < R; i++) {
                TrieNode *p = links[i];
                if (p != nullptr && searchWord(word, p, pos + 1)) {
                    return true;
                }
            }
            return false;
        } else {
            TrieNode *p = links[word[pos] - 'a'];
            return (p != nullptr && searchWord(word, p, pos + 1));
        }
    }
public:
    WordDictionary() {
        root = new TrieNode();
    }
    void addWord(string word) {
        TrieNode *node = root;
        for (char ch: word) {
            if (!node->containsKey(ch)) {
                node->put(ch, new TrieNode());
            }
            node = node->get(ch);
        }
        node->setEnd();
    }
    bool search(string word) {
        return searchWord(word, root, 0);
    }
};

int main() {
    WordDictionary wd;
    wd.addWord("bad");
    wd.addWord("dad");
    wd.addWord("mad");
    cout << wd.search("pad") << endl;
    cout << wd.search("bad") << endl;
    cout << wd.search(".ad") << endl;
    cout << wd.search("..d") << endl;
    return 0;
}