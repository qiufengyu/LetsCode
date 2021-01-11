#include "../header.h"

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> m(wordList.begin(), wordList.end());
        if (m.count(endWord) == 0) {
            return 0;
        }
        int res = 0;
        queue<string> q;
        q.push(beginWord);
        while (!q.empty()) {
            int sz = q.size();
            for (int i = 0; i < sz; i++) {
                string w = q.front();
                q.pop();
                if (w == endWord) {
                    return ++res;
                }
                for (int j = 0; j < w.size(); j++) {
                    string newWord {w};
                    for (char c = 'a'; c <= 'z'; c++) {
                        if (newWord[j] != c) {
                            newWord[j] = c;
                            if (m.count(newWord)) {
                                q.push(newWord);
                                m.erase(newWord);
                            }
                        }
                    }
                }
                
            }
            ++res;
        }
        return 0;
    }
};
