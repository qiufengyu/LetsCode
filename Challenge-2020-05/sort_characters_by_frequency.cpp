#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

class Solution {
public:
    string frequencySort(string s) {
        map<char, int> m;
        for (auto &c: s) {
            if (m.find(c) == m.end()) {
                m.insert({c, 1});
            } else {
                m.insert_or_assign(c, m[c] + 1);
            }
        }
        vector<pair<char, int>> v;
        for (auto &x: m) {
            v.push_back({x.first, x.second});
        }
        sort(v.begin(), v.end(), [](const pair<char, int> &a, const pair<char, int> &b) -> bool { return a.second > b.second;});
        string res;
        for (auto &i: v) {
            for (int j = 0; j < i.second; j++) {
                res.push_back(i.first); 
            }
        }
        return res;
    }
};


int main() {
    string s;
    cin >> s;
    cout << Solution().frequencySort(s) << endl;
    return 0;
}