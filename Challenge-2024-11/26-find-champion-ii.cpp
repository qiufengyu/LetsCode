#include "../header.h"

class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++) {
            mp[i] = 0;
        }
        for (int i = 0; i < edges.size(); i++) {
            mp[edges[i][1]]++;
        }
        unordered_set<int> st;
        for (auto const& p: mp) {
            if (p.second == 0) {
                st.insert(p.first);
            }
        }
        if (st.size() == 1) {
            return *st.begin();
        }
        return -1;
    }
};