#include "../header.h"

struct TrieNode {
    TrieNode *links[26];
    bool isEnd;
    string word;
    TrieNode(): isEnd {false}, word{""} {
        for (int i = 0; i < 26; i++) {
            links[i] = nullptr;
        }
    }
    void insert(const string& word) {
        TrieNode *node = this;
        for (char c: word) {
            int t = c - 'a';
            if (!node->links[t]) {
                node->links[t] = new TrieNode();
            }
            node = node->links[t];
        }
        node->word = word;
        node->isEnd = true;
    }
};

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> res;
        set<string> s;
        int n = board.size();        
        int m = board[0].size();        
        TrieNode *node = new TrieNode();
        for (auto w: words) {
            node->insert(w);
        }
        vector<vector<bool>> visited (n, vector<bool>(m, false));
        for (int i = 0; i < n; i ++) {
            for (int j = 0; j < m; j++) {
                find(board, node, i, j, n, m, visited, s);
            }
        }
        for (auto const& w: s) {
            res.push_back(w);
        }
        return res;        
    }

    void find(vector<vector<char>>& board, TrieNode* node, int i, int j, int n, int m, vector<vector<bool>>& visited, set<string>& res) {
        if (i < 0 || i == n || j < 0 || j == m || visited[i][j]) {
            return;
        }
        char ch = board[i][j];
        int t = ch - 'a';
        // cout << "search: " << p << endl;
        if (!node->links[t]) {
            return;
        }
        node = node->links[t];
        if (node->isEnd) {
            res.insert(node->word);
        }
        visited[i][j] = true;
        find(board, node, i-1, j, n, m, visited, res);
        find(board, node, i, j-1, n, m, visited, res);
        find(board, node, i+1, j, n, m, visited, res);
        find(board, node, i, j+1, n, m, visited, res);
        visited[i][j] = false;
    }
};

int main() {
    vector<vector<char>> board {{'o','a','a','n'},{'e','t','a','e'},{'i','h','k','r'},{'i','f','l','v'}};
    vector<string> words {"oath","pea","eat","rain"};
    auto res = Solution().findWords(board, words);
    print_vector<string>(res);
    return 0;
}
