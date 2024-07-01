#include "../header.h"

class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        unordered_map<int, int> mp;
        int mx = 0, res = 0;
        for (auto const& e: edges) {
            mp[e[0]]++;
            mp[e[1]]++;
            if (mp[e[0]] > mx) {
                mx = mp[e[0]];
                res = e[0];
            }
            if (mp[e[1]] > mx) {
                mx = mp[e[1]];
                res = e[1];
            }
        }
        return res;
    }
};