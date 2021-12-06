#include "../header.h"

static auto _ = [](){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 0;
}();

class Solution {
    unordered_map<string, string> m;
    unordered_map<string, string> n;
    void u1(const string& a) {        
        m[a] = get(a);
    }
    void u2(const string& a, const string& b) {
        string a1 = get(a);
        string b1 = get(b);
        m[b1] = a1;
    }
    string get(string a) {
        while (m.count(a) > 0 && m[a] != a) {
            a = m[a];
        }
        return a;
    }
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        for (auto const& account: accounts) {
            string name = account[0];
            u1(account[1]);
            n[account[1]] = name;
            for (int i = 2; i < account.size(); ++i) {
                n[account[i]] = name;
                u2(account[1], account[i]);
            }
        }
        map<string, set<string>> emails;
        vector<vector<string>> res;
        for (auto& p: m) {
            emails[get(p.second)].insert(p.first);            
            // cout << n[p.first] << ": " << p.first << " -> " << p.second << endl;
        }
        for (auto& p: emails) {
            string name = n[p.first];
            vector<string> v {name};
            v.insert(v.end(), p.second.begin(), p.second.end());
            res.push_back(v);
        }
        return res;
    }
};