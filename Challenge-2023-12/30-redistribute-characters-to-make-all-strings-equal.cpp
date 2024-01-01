#include "../header.h"

class Solution {
public:
    bool makeEqual(vector<string>& words) {
        unordered_map<char, int> m;
        int n = words.size();
        for (auto const& w: words) {
            for (int i = 0; i < w.size(); i++) {
                m[w[i]]++;
            }
        }
        for (auto const& p: m) {
            if ((p.second % n) != 0) {
                return false;
            }
        }
        return true;
    }
};