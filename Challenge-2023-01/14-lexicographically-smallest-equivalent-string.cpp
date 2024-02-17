#include "../header.h"

class Solution {
    vector<char> v;
public:
    void u(char c1, char c2) {
        char f1 = f(c1);
        char f2 = f(c2);
        v[f1-'a'] = f2;
    }

    char f(char c) {
        if (v[c-'a'] == c) {
            return c;
        } else {
            return f(v[c-'a']);
        }
    }

    Solution(): v(vector<char>(26, 0)) {
        for (int i = 0; i < 26; ++i) {
            v[i] = ('a' + i);
        }
    }

    string smallestEquivalentString(string s1, string s2, string baseStr) {
        int n = s1.size();
        for (int i = 0; i < n; ++i) {
            u(s1[i], s2[i]);
        }
        unordered_map<char, char> m1;
        unordered_map<char, set<char>> m2;
        for (char i = 'a'; i <= 'z'; ++i) {
            char c = f(i);
            if (m2.count(c)) {
                m2[c].insert(i);
            } else {
                m2[c] = {i};
            }
        }
        for (auto const& p: m2) {
            auto s = p.second;
            char mc = 'z';
            for (auto c: s) {
                mc = min(mc, c);
                m1[c] = mc;
            }
        }
        string res{baseStr};
        for (int i = 0; i < baseStr.size(); ++i) {
            if (m1.count(baseStr[i])) {
                res[i] = m1[baseStr[i]];
            }
        }
        return res;
    }
};

int main() {
    string s1 = "leetcode", s2 = "programs", baseStr = "sourcecode";
    string res = Solution().smallestEquivalentString(s1, s2, baseStr);
    cout << res << endl;
    return 0;
}