#include "../header.h"

class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        if (dict.find(endWord) == dict.end()) {
            return {};
        }
        vector<vector<string>> res;
        dict.erase(beginWord);
        unordered_map<string, int> depths;
        depths[beginWord] = 0;
        unordered_map<string, set<string>> graph;
        int step = 0;
        bool found = false;
        queue<string> q;
        q.push(beginWord);
        int l = beginWord.size();
        while (!q.empty()) {
            step++;
            int sz = q.size();
            for (int i = 0; i < sz; ++i) {
                string current = q.front();
                string nextWord = current;
                q.pop();
                for (int j = 0; j < l; ++j) {
                    char origin = current[j];
                    for (char c = 'a'; c <= 'z'; ++c) {
                        nextWord[j] = c;
                        if (depths[nextWord] == step) {            
                            graph[nextWord].insert(current);
                        }
                        if (dict.find(nextWord) == dict.end()) {
                            continue;
                        }
                        dict.erase(nextWord);
                        q.push(nextWord);
                        graph[nextWord].insert(current);
                        depths[nextWord] = step;
                        if (nextWord == endWord) {
                            found = true;
                        }
                    }
                    nextWord[j] = origin;
                }
            }
            if (found) {
                break;
            }
        }
        if (found) {
            vector<string> path = {endWord};
            dfs(res, endWord, graph, path);
        }
        return res;
    }

    void dfs(vector<vector<string>>& res, const string& word, unordered_map<string, set<string>> graph, vector<string>& path) {
        if (graph[word].empty()) {
            res.push_back({path.rbegin(), path.rend()});
            return;
        }
        for (const string& parent: graph[word]) {
            path.push_back(parent);
            dfs(res, parent, graph, path);
            path.pop_back();
        }
    }
};

int main() {
    string s1, s2;
    cin >> s1 >> s2;
    string s;
    cin >> s;
    vector<string> d = stringToStringVector(s);
    auto res = Solution().findLadders(s1, s2, d);
    print_vector<string>(res);
    return 0;
}