#include "header.h"

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
        for (char ch: word) {
            if (!node->containsKey(ch)) {
                node->put(ch, new TrieNode());
            }
            node = node->get(ch);
        }
        node->setEnd();
    }
    TrieNode* searchPrefix(string word) {
        TrieNode *node = root;
        for (char ch: word) {
            if (node->containsKey(ch)) {
                node = node->get(ch);
            } else {
                return nullptr;
            }
        }
        return node;
    }
    bool search(string word) {
        TrieNode *node = searchPrefix(word);
        return node != nullptr && node->getEnd();
    }
    bool startsWith(string prefix) {
        TrieNode *node = searchPrefix(prefix);
        return node != nullptr;
    }
};

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> res;
        int n = board.size();
        if (n == 0) {
            return res;
        }
        int m = board[0].size();
        if (m == 0) {
            return res;
        }
        Trie *t = new Trie();
        for (auto w: words) {
            t->insert(w);
        }
        vector<vector<bool>> visited (n, vector<bool>(m, false));
        for (int i = 0; i < n; i ++) {
            for (int j = 0; j < m; j++) {
                string p = "";
                find(board, t, p, i, j, n, m, visited, res);
            }
        }
        sort(res.begin(), res.end());
        res.erase(unique(res.begin(), res.end()), res.end());
        return res;        
    }

    void find(vector<vector<char>>& board, Trie* node, string p, int i, int j, int n, int m, vector<vector<bool>>& visited, vector<string>& res) {
        if (i < 0 || i == n || j < 0 || j == m || visited[i][j]) {
            return;
        }
        char ch = board[i][j];
        p.push_back(ch);
        cout << "search: " << p << endl;
        if (!node->startsWith(p)) {
            return;
        }
        if (node->search(p)) {
            res.push_back(p);
        }
        visited[i][j] = true;
        find(board, node, p, i-1, j, n, m, visited, res);
        find(board, node, p, i, j-1, n, m, visited, res);
        find(board, node, p, i+1, j, n, m, visited, res);
        find(board, node, p, i, j+1, n, m, visited, res);
        visited[i][j] = false;
    }
};

int main() {
    vector<vector<char>> board {{'o','a','a','n'}, {'e','t','a','e'}, {'i','h','k','r'}, {'i','f','l','v'}};
    vector<string> words {"oath","pea","eat","rain"};
    vector<string> res = Solution().findWords(board, words);
    for (auto r: res) cout << r << endl;
    return 0;
}

