#include "../header.h"

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<string> q;
        unordered_set<string> m(wordList.begin(), wordList.end());
        if (m.count(endWord) == 0) {
            return 0;
        }
        int res = 0;
        q.push(beginWord);
        while (!q.empty()) {
            int sz = q.size();
            for (int i = 0; i < sz; ++i) {
                string s = q.front();
                q.pop();
                if (s == endWord) {
                    ++res;
                    return res;
                }
                for (int j = 0; j < s.size(); ++j) {
                    string temp {s};
                    for (char c = 'a'; c <= 'z'; ++c) {
                        if (temp[j] != c) {
                            temp[j] = c;
                            if (m.count(temp)) {
                                q.push(temp);
                                m.erase(temp);
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