#include "../header.h"

class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_set<string> c1, c2;
        for (auto const& p: paths) {
            c1.insert(p[0]);
            c2.insert(p[1]);
        }
        for (auto const& e: c2) {
            if (c1.find(e) == c1.end()) {
                return e;
            }
        }
        return "";
    }
};