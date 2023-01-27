#include "../header.h"

class Solution {
    bool diff(string const& a, string const& b) {
        int d = 0;
        for (int i = 0; i < 8; ++i) {
            if (a[i] != b[i]) {
                ++d;
            }
        }
        return d == 1;
    }
public:
    int minMutation(string start, string end, vector<string>& bank) {
        unordered_map<string, set<string>> m;
        unordered_map<string, bool> visited;
        queue<string> q;
        int n = bank.size();
        for (int i = 0; i < n; ++i) {            
            string a = bank[i];
            visited[a] = false;
            for (int j = i + 1; j < n; ++j) {
                string b = bank[j];
                if (diff(a, b)) {
                    m[a].insert(b);
                    m[b].insert(a);
                }
            }
            if (diff(start, a)) {
                q.push(a);
            }
        }        
        if (visited.count(end) == 0) {
            return -1;
        }
        if (start == end) {
            return 0;
        }
        int res = 1;
        while (!q.empty()) {
            int sz = q.size();
            for (int i = 0; i < sz; ++i) {
                string t = q.front();
                q.pop();
                visited[t] = true;
                if (t == end) {
                    return res;
                }
                for (auto const& s: m[t]) {
                    if (!visited[s]) {
                        q.push(s);
                    }
                }
            }
            ++res;
        }
        return -1;
    }
};