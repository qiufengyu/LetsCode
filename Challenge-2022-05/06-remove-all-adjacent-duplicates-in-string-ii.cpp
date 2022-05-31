#include "../header.h"

class Solution {
public:
    string removeDuplicates(string s, int k) {
        vector<pair<int, char>> st = {{0, '#'}};
        for (char c: s) {
            if (st.back().second != c) {
                st.push_back({1, c});
            } else {
                auto& prev = st.back();
                prev.first += 1;
                if (prev.first == k) {
                    st.pop_back();
                }
            }
        }
        string res;
        for (auto& p: st) {
            res.append(p.first, p.second);
        }
        return res;
    }
};