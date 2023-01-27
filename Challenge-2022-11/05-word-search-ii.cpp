#include "../header.h"

struct Trie {
    string word;
    bool leaf;
    vector<Trie*> children;
    Trie(): children(26, nullptr) {
        leaf = false;
    }
};

void add(Trie* t, string const& s) {
    int n = s.size();
    for (int i = 0; i < n - 1; ++i) {
        char c = s[i];
        int idx = c - 'a';
        if (t->children[idx] == nullptr) {
            t->children[idx] = new Trie();
        }
        t = t->children[idx];
    }
    int e = s[n-1] - 'a';
    if (t->children[e] == nullptr) {
        t->children[e] = new Trie();
    }
    t->children[e]->leaf = true;
    t->children[e]->word = s;
}

class Solution {
    void dfs(vector<vector<char>>& board, int i, int j, Trie *t, set<string>& res, vector<vector<bool>> &visited, const int m, const int n) {
        if (i < 0 || j < 0 || i >= m || j >= n) {
            return;
        }
        int index = board[i][j] - 'a';
        cout << board[i][j] << endl;
        if (t->children[index] == nullptr || visited[i][j]) {
            return;
        }
        if (t->children[index]->leaf) {
            res.insert(t->children[index]->word);
        }
        visited[i][j] = true;        
        dfs(board, i+1, j, t->children[index], res, visited, m, n);
        dfs(board, i-1, j, t->children[index], res, visited, m, n);
        dfs(board, i, j+1, t->children[index], res, visited, m, n);
        dfs(board, i, j-1, t->children[index], res, visited, m, n);        
        visited[i][j] = false;
    }
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        set<string> res;
        int m = board.size(), n = board[0].size();
        Trie *t = new Trie();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        for (string const& w: words) {
            add(t, w);
        }
        Trie* t1 = t->children['o' - 'a'];
        cout << t1->leaf << ": " << t1->word<< endl;
        Trie *t2 = t1->children['a'-'a'];
        cout << t2->leaf << ": " << t2->word<< endl;
        Trie *t3 = t2->children['t'-'a'];
        cout << t3->leaf << ": " << t3->word<< endl;
        Trie *t4 = t3->children['h'-'a'];
        cout << t4->leaf << ": " << t4->word<< endl;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                dfs(board, i, j, t, res, visited, m, n);
            }
        }
        vector<string> r(res.begin(), res.end());
        return r;
    }
};

int main() {
    vector<vector<char>> board{{'o','a','a','n'},{'e','t','a','e'},{'i','h','k','r'},{'i','f','l','v'}};
    vector<string> words {"oath","pea","eat","rain"};
    vector<string> res = Solution().findWords(board, words);
    cout << res.size() << endl;
    return 0;
}