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
};


class Trie {
private:
    TrieNode *root;
public:
    Trie() {
        root = new TrieNode();
    }
    void insert(string word) {
        TrieNode *node = root;
        for (int i = word.length() - 1; i >= 0 ; i--) {
            char ch = word[i];
            if (!node->containsKey(ch)) {
                node->put(ch, new TrieNode());
            }
            node = node->get(ch);
        }
        node->setEnd();
    }
    
    bool search(string& word) {
        TrieNode *node = root;
        for (int i = word.length() - 1; i >= 0; i--) {
            node = node->get(word[i]);
            if (node == nullptr) {
                return false;
            }
            if (node->getEnd()) {
                return true;
            }
        }
        return false;
    }
    
};

class StreamChecker {
private:
    Trie trie;
    string stream {""};
    size_t maxLen = 0;
public:
    StreamChecker(vector<string>& words) {
        trie = Trie();
        for (auto word: words) {
            trie.insert(word);
            maxLen = max(maxLen, word.length());
        }
    }
    
    bool query(char letter) {
        stream.push_back(letter);
        if (stream.size() > maxLen) {
            stream.erase(stream.begin());
        }
        return trie.search(stream);
    }
};

int main() {
    vector<string> dict {"cd", "f", "kl"};
    StreamChecker streamChecker(dict);
    cout << streamChecker.query('a') << endl;          // return false
    cout << streamChecker.query('b') << endl;          // return false
    cout << streamChecker.query('c') << endl;          // return false
    cout << streamChecker.query('d') << endl;          // return true, because 'cd' is in the wordlist
    cout << streamChecker.query('e') << endl;          // return false
    cout << streamChecker.query('f') << endl;          // return true, because 'f' is in the wordlist
    cout << streamChecker.query('g') << endl;          // return false
    cout << streamChecker.query('h') << endl;          // return false
    cout << streamChecker.query('i') << endl;          // return false
    cout << streamChecker.query('j') << endl;          // return false
    cout << streamChecker.query('k') << endl;          // return false
    cout << streamChecker.query('l') << endl;          // return true, because 'kl' is in the wordlist
    return 0;
}