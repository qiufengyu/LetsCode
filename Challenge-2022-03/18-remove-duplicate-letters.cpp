#include "../header.h"

class Solution {
public:
    string removeDuplicateLetters(string s) {
        unordered_map<char, int> m;
        unordered_map<char, bool> visited;
        string res = "";
        for (int i = 0; i < s.size(); ++i) {
            ++m[s[i]];
        }
        for (int i = 0; i < s.size(); ++i) {
            char c = s[i];
            --m[c];
            if (visited[c]) {
                continue;
            }
            while (res.size() > 0 && c < res.back() && m[res.back()] > 0) {
                visited[res.back()] = false;
                res.pop_back();
            }
            res += c;
            visited[c] = true;
        }
        return res;
    }
};