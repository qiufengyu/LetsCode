#include "../header.h"

class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char, int> m;
        for (auto const& c: text) {
            ++m[c];
        }
        int res = m['b'];
        res = min(res, m['a']);
        res = min(res, m['l'] / 2);
        res = min(res, m['o'] / 2);
        res = min(res, m['n']);
        return res;
    }
};