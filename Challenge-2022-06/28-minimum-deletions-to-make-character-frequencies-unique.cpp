#include "../header.h"

class Solution {
public:
    int minDeletions(string s) {
        map<int, vector<char>> ic;
        unordered_map<char, int> ci;
        unordered_map<int, char> icNew;
        int res = 0;
        for (auto const& c: s) {
            ++ci[c];
        }
        for (auto const& p: ci) {
            if (ic.count(-p.second)) {
                ic[-p.second].push_back(p.first);
            } else {
                ic[-p.second] = {p.first};
            }
            icNew[-p.second] = ic[-p.second][0];
        }
        for (auto const& p: ic) {
            auto l = p.second;
            int cnt = p.first;
            if (l.size() > 1) {
                // allocate proper count for other chars
                for (int i = 1; i < l.size(); ++i) {
                    while (icNew.count(cnt) && cnt < 0) {
                        cnt++;
                    }                   
                    res -= (p.first - cnt);                    
                    icNew[cnt] = l[i];
                }
            }
        }
        return res;
    }
};

int main() {
    string s;
    cin >> s;
    cout << Solution().minDeletions(s) << endl;
    return 0;
}