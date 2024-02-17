#include "../header.h"

class Solution {
    unordered_map<string, string> m;
public:
    void u(string const& s1, string const& s2) {
        string f1 = f(s1);
        string f2 = f(s2);
        if (f1 != f2) {
            m[f2] = f1;
        }
    }

    string f(string s) {
        while (m[s] != s) {
            s = m[s];
        }
        return m[s];
    }

    bool sim(const string& s1, const string& s2) {
        int d = 0;
        for (int i = 0; i < s1.size(); ++i) {
            if (s1[i] != s2[i]) {
                d++;
            }
        }
        return (d == 0 || d == 2);
    }

    int numSimilarGroups(vector<string>& strs) {
        int n = strs.size();
        for (int i = 0; i < n; ++i) {
            m[strs[i]] = strs[i];
        }
        for (int i = 0; i < n - 1; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (sim(strs[i], strs[j])) {
                    u(strs[i], strs[j]);
                }
            }
        }
        // count groups, the input array may contain same strings
        // use a set to do counting
        unordered_set<string> st;
        for (int i = 0; i < n; ++i) {
            if (m[strs[i]] == strs[i]) {
                st.insert(strs[i]);
            }
        }
        return (int)st.size();
    }
};