#include "header.h"

class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        vector<string> res;
        unordered_map<string, multiset<string>> m;
        for (auto t: tickets) {
            m[t[0]].insert(t[1]);
        }
        dfs("JFK", m, res);
        reverse(res.begin(), res.end());
        return res;
    }

    void dfs(string s, unordered_map<string, multiset<string>>& m, vector<string>& res) {
        while (m[s].size() > 0) {
            string t = *m[s].begin();
            m[s].erase(m[s].begin());
            dfs(t, m, res);
        }
        res.push_back(s);
    }
    
};

int main() {

}